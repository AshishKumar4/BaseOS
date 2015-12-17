extern void Pixel_VESA_BUFF();
	const int Dote[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Utro[] = { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapA[] = { 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlA[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapB[] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlB[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapC[] = { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlC[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapD[] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlD[] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapE[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlE[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapF[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlF[] = { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapG[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlG[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0 };

	const int CapH[] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlH[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapI[] = { 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlI[] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapJ[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlJ[] = { 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

	const int CapK[] = { 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlK[] = { 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapL[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlL[] = { 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapM[] = { 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlM[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapN[] = { 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlN[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapO[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlO[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapP[] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlP[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 };

	const int CapQ[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 };

	const int SmlQ[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

	const int CapR[] = { 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlR[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapS[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlS[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapT[] = { 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlT[] = { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapU[] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlU[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapV[] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlV[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapW[] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlW[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapX[] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlX[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int CapY[] = { 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlY[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0 };

	const int CapZ[] = { 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int SmlZ[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Null[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Zero[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int One[] = { 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Two[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Three[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Four[] = { 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Five[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Six[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Seven[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Eight[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Nine[] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	const int Colon[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };



	//16x16
	const int Logo2[] =
	{
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	};// 16 by 16 onhow om cla te maak

	const int Loading1of4[] =
	{
		1, 0, 0, 0,
	};

	const int Loading2of4[] =
	{
		0, 1, 0, 0,
	};

	const int Loading3of4[] =
	{
		0, 0, 1, 0,
	};

	const int Loading4of4[] =
	{
		0, 0, 0, 1,
	};
void DrawTextChar(int x, int y, int font[],int color,int size)
{
    int c = 0;
    for (int p = y; p < y + 9+size; p++)
    {
        for (int i = x; i < x + 5+size; i++)
        {
            if (font[c] == 1)
            {
                Pixel_VESA_BUFF(i, p, color,color,color);
            }

            c = c + 1;
        }
    }
}
 void WriteText(char *Text, int Textx, int Texty, int Color, int size)
{
	char a;
	for (int i = 0; Text[i] != '\0'; i++)
	{
		a = Text[i];
		if (a == 'A')
		{
			DrawTextChar(Textx, Texty,  CapA, Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'a')
		{
			DrawTextChar(Textx, Texty,  SmlA,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'B')
		{
			DrawTextChar(Textx, Texty,  CapB,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'b')
		{
			DrawTextChar(Textx, Texty,  SmlB,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'C')
		{
			DrawTextChar(Textx, Texty,  CapC,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'c')
		{
			DrawTextChar(Textx, Texty,  SmlC,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'D')
		{
			DrawTextChar(Textx, Texty,  CapD,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'd')
		{
			DrawTextChar(Textx, Texty,  SmlD,Color, size);
			Textx = Textx + 6;
		}

		else if (a == 'E')
		{
			DrawTextChar(Textx, Texty,  CapE,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'e')
		{
			DrawTextChar(Textx, Texty,  SmlE,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'F')
		{
			DrawTextChar(Textx, Texty,  CapF,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'f')
		{
			DrawTextChar(Textx, Texty,  SmlF,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'G')
		{
			DrawTextChar(Textx, Texty,  CapG,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'g')
		{
			DrawTextChar(Textx, Texty,  SmlG,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'H')
		{
			DrawTextChar(Textx, Texty,  CapH,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'h')
		{
			DrawTextChar(Textx, Texty,  SmlH,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'I')
		{
			DrawTextChar(Textx, Texty,  CapI,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'i')
		{
			DrawTextChar(Textx, Texty,  SmlI,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'J')
		{
			DrawTextChar(Textx, Texty,  CapJ,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'j')
		{
			DrawTextChar(Textx, Texty,  SmlJ,Color, size);
			Textx = Textx + 6;
		}

		else if (a == 'K')
		{
			DrawTextChar(Textx, Texty,  CapK,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'k')
		{
			DrawTextChar(Textx, Texty,  SmlK,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'L')
		{
			DrawTextChar(Textx, Texty,  CapL,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'l')
		{
			DrawTextChar(Textx, Texty,  SmlL,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'M')
		{
			DrawTextChar(Textx, Texty,  CapM,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'm')
		{
			DrawTextChar(Textx, Texty,  SmlM,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'N')
		{
			DrawTextChar(Textx, Texty,  CapN,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'n')
		{
			DrawTextChar(Textx, Texty,  SmlN,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'O')
		{
			DrawTextChar(Textx, Texty,  CapO,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'o')
		{
			DrawTextChar(Textx, Texty,  SmlO,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'P')
		{
			DrawTextChar(Textx, Texty,  CapP,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'p')
		{
			DrawTextChar(Textx, Texty,  SmlP,Color, size);
			Textx = Textx + 6;
		}

		else if (a == 'Q')
		{
			DrawTextChar(Textx, Texty,  CapQ,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'q')
		{
			DrawTextChar(Textx, Texty,  SmlQ,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'R')
		{
			DrawTextChar(Textx, Texty,  CapR,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'r')
		{
			DrawTextChar(Textx, Texty,  SmlR,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'S')
		{
			DrawTextChar(Textx, Texty,  CapS,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 's')
		{
			DrawTextChar(Textx, Texty,  SmlS,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'T')
		{
			DrawTextChar(Textx, Texty,  CapT,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 't')
		{
			DrawTextChar(Textx, Texty,  SmlT,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'U')
		{
			DrawTextChar(Textx, Texty,  CapU,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'u')
		{
			DrawTextChar(Textx, Texty,  SmlU,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'V')
		{
			DrawTextChar(Textx, Texty,  CapV,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'v')
		{
			DrawTextChar(Textx, Texty,  SmlV,Color, size);
			Textx = Textx + 6;
		}

		else if (a == 'W')
		{
			DrawTextChar(Textx, Texty,  CapW,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'w')
		{
			DrawTextChar(Textx, Texty,  SmlW,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'X')
		{
			DrawTextChar(Textx, Texty,  CapX,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'x')
		{
			DrawTextChar(Textx, Texty,  SmlX,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'Y')
		{
			DrawTextChar(Textx, Texty,  CapY,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'y')
		{
			DrawTextChar(Textx, Texty,  SmlY,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'Z')
		{
			DrawTextChar(Textx, Texty,  CapZ,Color, size);
			Textx = Textx + 6;
		}
		else if (a == 'z')
		{
			DrawTextChar(Textx, Texty,  SmlZ,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '.')
		{
			DrawTextChar(Textx, Texty,  Dote,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '!')
		{
			DrawTextChar(Textx, Texty,  Utro,Color, size);
			Textx = Textx + 6;
		}
		else if (a == ' ')
		{
			DrawTextChar(Textx, Texty,  Null,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '0')
		{
			DrawTextChar(Textx, Texty,  Zero,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '1')
		{
			DrawTextChar(Textx, Texty,  One,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '2')
		{
			DrawTextChar(Textx, Texty,  Two,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '3')
		{
			DrawTextChar(Textx, Texty,  Three,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '4')
		{
			DrawTextChar(Textx, Texty,  Four,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '5')
		{
			DrawTextChar(Textx, Texty,  Five,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '6')
		{
			DrawTextChar(Textx, Texty,  Six,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '7')
		{
			DrawTextChar(Textx, Texty,  Seven,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '8')
		{
			DrawTextChar(Textx, Texty,  Eight,Color, size);
			Textx = Textx + 6;
		}
		else if (a == '9')
		{
			DrawTextChar(Textx, Texty,  Nine,Color, size);
			Textx = Textx + 6;
		}
		else if (a == ':')
		{
			DrawTextChar(Textx, Texty,  Colon,Color, size);
			Textx = Textx + 6;
		}
	}
}
