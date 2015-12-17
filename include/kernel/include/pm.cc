#include "pm.h"
#include "stdio.h"

unsigned long *pm_dir = 0;
unsigned long ____pm_slack = 0;

#ifdef DEBUG_INFO
#define KDBGINFO kprintf("%s:%s:%u:", __FILE__, __FUNCTION__, __LINE__); kprintf
#else
#define KDBGINFO //
#endif
#ifdef DEBUG_WARN
#define KDBGWARN kprintf("%s:%s:%u:", __FILE__, __FUNCTION__, __LINE__); kprintf
#else
#define KDBGWARN //
#endif
#ifdef DEBUG_ERROR
#define KDBGERROR kprintf("%s:%s:%u:", __FILE__, __FUNCTION__, __LINE__); kprintf
#else
#define KDBGERROR //
#endif


#define PM_TES_MAX 4
struct pm_tes
{
	unsigned long page;
	unsigned long count;
	unsigned long code;
};

pm_tes ____pm_tes[PM_TES_MAX];
unsigned char ____pm_tes_cnt = 0;

/// specialized initialization function
int pm_init_with_grub_mmap(unsigned long mmap_addr, unsigned long mmap_length)
{
	KDBGINFO("Called; mmap_addr:%x mmap_length:%x\n", mmap_addr, mmap_length);
	if((mmap_addr | mmap_length) == 0)
	{
		KDBGERROR("No memory map found.\n");
		// problems!
		return -1;
	}
	pm_tmbmm *mm = (pm_tmbmm*)mmap_addr;
	for(; ((unsigned long)mm) < (mmap_addr + mmap_length); mm = (pm_tmbmm*)((unsigned int)mm + mm->size + 4))
	{
		KDBGINFO("base:%x size:%x type:%x\n", mm->base_low, mm->size_low, mm->type);
		if(mm->type == 0x1){
			// hand range to pm_init function. (we should always get whole pages; if not oh well..)
			if(mm->size_low > 4095)
			{
				pm_init(mm->base_low & 0xFFFFF000, mm->size_low >> 12);
			}else{
				KDBGWARN("memory region size below required 4096 byte; memory not accounted.\n");
			}
		}
	}
	KDBGINFO("initialization complete.\n");
	return 1;
}

/// build dynamic tree to track 4GB of memory.
void pm_init(unsigned long page, unsigned long count)
{
	unsigned long *tbl;
	if(count == 1)
	{
		KDBGWARN("mem region ignored because of size.\n");
		return;
	}
	if(page == 0)
	{
		++page;
		--count;
	}
	if(pm_dir == 0)
	{
		pm_dir = (unsigned long*)page;
		for(unsigned int x = 0; x < 1024; ++x)
		{
			pm_dir[x] = 0;
		}
		--page;
		--count;
	}
	for(unsigned int x = 0; x < count; ++x)
	{
		for(unsigned int y = 0; y < ____pm_tes_cnt; ++y)
		{
			if(((page + (x * 4096)) >= ____pm_tes[y].page) && ((page + (x * 4096)) < (____pm_tes[y].page + (____pm_tes[y].count * 4096))))
			{
				// page is protected by ____pm_tes at this moment..
				continue;
			}
		}
		if(!____pm_slack)
		{
			____pm_slack = page + (x * 4096);
		}else{
			if(!pm_dir[(page + (x * 4096))>>22])
			{
				pm_dir[(page + (x * 4096))>>22] = ____pm_slack;
				tbl = (unsigned long*)____pm_slack;
				for(unsigned int y = 0; y < 1024; ++y)
				{
					tbl[y] = 0;
				}
			}else{
				tbl = (unsigned long*)(pm_dir[(page + (x * 4096))>>22] & 0xFFFFF000);
			}
			tbl[(page + (x * 4096))<<10>>10>>12] = PM_VALID;
		}
	}
	return;
}

int pm_free(unsigned long page)
{
	unsigned long *tbl;
	if(!pm_dir[page>>22])
	{
		KDBGINFO("page never existed: %x\n", page);
		// this page must have never been in this system to begin with, a bug causing this bad call?
		return -1;
	}
	tbl = (unsigned long*)(pm_dir[page>>22] & 0xFFFFF000);
	if(!tbl[page<<10>>10>>12])
	{
		KDBGINFO("page never existed: %x\n", page);
		// this page must have never been in this system to begin with, a bug causing this bad call?
		return -1;
	}
	// clear all bits, but the valid one.
	tbl[page<<10>>10>>12] = PM_VALID;
	return 1;
}
int pm_free(unsigned long page, unsigned long count)
{
	int result;
	for(unsigned int x = 0; x < count; ++x)
	{
		result |= pm_free(page + (x * 4096));
	}
	return result;
}
void pm_set_flush()
{
	if(!pm_dir)
	{
		KDBGWARN("can not flush with no accounted memory.\n");
		return;
	}
	for(unsigned int x = 0; x < ____pm_tes_cnt; ++x)
	{
		KDBGINFO("flushed cmd in tes (%x,%x,%x)\n", ____pm_tes[x].page, ____pm_tes[x].count, ____pm_tes[x].code);
		pm_set(____pm_tes[x].page, ____pm_tes[x].count, ____pm_tes[x].code);
	}
	____pm_tes_cnt = 0;
}
void pm_set(unsigned long page, unsigned long count, unsigned long code)
{
	unsigned long *tbl;
	if(!pm_dir)
	{
		KDBGINFO("saved cmd in tes (%x,%x,%x)\n", page, count, code);
		// save command for during initialization and after.
		____pm_tes[____pm_tes_cnt].page = page;
		____pm_tes[____pm_tes_cnt].count = count;
		____pm_tes[____pm_tes_cnt].code = code;
		++____pm_tes_cnt;
		if(____pm_tes_cnt > PM_TES_MAX)
		{
			// display error, and halt machine hopefully! (should happen in early boot stages)
			KDBGERROR("____pm_tes_cnt exceeded PE_TES_MAX\n");
			for(;;);
		}
		return;
	}
	for(unsigned long x = 0; x < count; ++x)
	{
		if(!pm_dir[page>>22])
		{
			pm_dir[page>>22] = pm_alloc(1);
			if(pm_dir[page>>22] == 0)
			{
				KDBGWARN("____pm_tes cmd failed; no memory.\n");
				continue;
			}
			tbl = (unsigned long*)(pm_dir[page>>22] & 0xFFFFF000);
			for(unsigned int y = 0; y < 1024; ++y)
			{
				tbl[y] = 0;	
			}
		}else{
			tbl = (unsigned long*)(pm_dir[page>>22] & 0xFFFFF000);
		}
		tbl[(page + (x * 4096))<<10>>10>>12] = code;
	}
	return;
}
unsigned long pm_alloc(unsigned long from, unsigned long to, unsigned long count, unsigned long tag)
{
	unsigned long origin;
	unsigned long *tbl;
	unsigned long found = 0;
	to += 4096;
	origin = from;
	// keep bugs and bad calls from screwing us up..hopefully.
	tag = tag & (~PM_FLAG_MASK);
	from = from & 0xFFFFF000;
	to = to & 0xFFFFF000;
	// search for free pages.
	for(unsigned long page = from; page <= to; page += 4096)
	{
		if(pm_dir[page>>22])
		{
			tbl = (unsigned long*)(pm_dir[page>>22] & 0xFFFFF000);
			//kprintf("[%x:%x]", page, tbl[page<<10>>10>>12]);
			if(
				(tbl[page<<10>>10>>12] & PM_VALID) &&
				!(tbl[page<<10>>10>>12] & PM_USED)
				)
			{
				++found;
				if(found >= count)
				{
					// allocate pages, now.
					for(page = origin; page < (origin + (4096 * count)); page += 4096)
					{
						tbl = (unsigned long*)(pm_dir[page>>22] & 0xFFFFF000);
						tbl[page<<10>>10>>12] = PM_VALID | PM_USED | tag;
					}
					return origin;
				}
			}else{
				found = 0;
				// if next page is valid and free then we already have it's address instead of adding
				// a additional if (above) to check the value of origin.
				origin = page + 0x1000;
			}
		}else{
			// skip the 4mb table (it does not exist - not worth continually checking again and again)
			page = page + (4096 * 1024);
		}
	}
	// we just never allocate page address zero; use it for something else such as: gdt, idt ...
	return 0;
}
unsigned long pm_alloc(unsigned long from, unsigned long to, unsigned long count)
{
	// no tag.
	return pm_alloc(from, to, count, 0);
}
unsigned long pm_alloc(unsigned long count)
{
	// no range specification.
	return pm_alloc(0x1000, 0xEFFFF000, count);
}
unsigned long pm_alloc()
{
	// no count specified.
	return pm_alloc(1);
}

