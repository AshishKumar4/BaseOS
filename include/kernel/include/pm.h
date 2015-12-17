#ifndef PM_H
#define PM_H
#define PM_FLAG_MASK 0xFFF						/// allows extra information to be tagged to entires that does not affect us.
#define PM_VALID 0x001							/// if page exists in system; the state might be otherwise.
#define PM_USED 0x002							/// the state of this page is used!

#define DEBUG_INFO
#define DEBUG_WARN
#define DEBUG_ERROR

/// allocate specified number of pages starting at 'from' and ending at 'to', and add tag to pages on success.
unsigned long pm_alloc(unsigned long from, unsigned long to, unsigned long count, unsigned long tag);
/// allocate specified number of pages starting at 'from' and ending at 'to'.
unsigned long pm_alloc(unsigned long from, unsigned long to, unsigned long count);
/// allocate specified number of pages.
unsigned long pm_alloc(unsigned long count);
/// allocate one page
unsigned long pm_alloc();
/// free specified number of contigious pages starting at page.
int pm_free(unsigned long page, unsigned long count);
/// free one page.
int pm_free(unsigned long page);

/// @internal control
void pm_set(unsigned long page, unsigned long count, unsigned long code);
void pm_set_flush();

/// @common initialization
void pm_init(unsigned long page, unsigned long count);
/// @specialized initialization
struct pm_tmbmm{
	unsigned long	size;
	unsigned long	base_low;
	unsigned long	base_high;
	unsigned long	size_low;
	unsigned long	size_high;
	unsigned long	type;
};
int pm_init_with_grub_mmap(unsigned long mmap_addr, unsigned long mmap_length);
#endif

