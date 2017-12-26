#include "stdafx.h"

namespace Chapter2
{
	// returns encoded truth table
	// 0 0 0 0 B'A' B'A BA' BA
	char loadTable(unsigned int i, unsigned int j, unsigned int k, unsigned int l)
	{
		if (i > 1 || j > 1 || k > 1 || l > 1)
		{
			return -1;
		}
		char tbl = 0;
		tbl |= (i << 3);
		tbl |= (j << 2);
		tbl |= (k << 1);
		tbl |= (l << 0);
		return tbl;
	}

	// returns true/false based on the table lookup 
	// provided in tbl
	// -- requirement is don't use "generic logic function"
	bool evaluate(char tbl, bool A, bool B)
	{
		int mask;
		mask = A ? 4 : 8;
		mask /= B ? 2 : 1;
		return tbl & mask > 0;
	}

	char* displayTbl4Bit(char tbl)
	{
		char nib0 = tbl &= 0x0F;
		char buff[80];
		sprintf(buff, "B'A' : %d, B'A : %d, BA' : %d, BA : %d", (nib0 >> 3) & 1, (nib0 >> 2) & 1, (nib0 >> 1) & 1, (nib0 >> 0) & 1);
		return buff;
	}

	char* displayTbl8Bit(char tbl)
	{
		char buff[120];
		sprintf(buff, "C'B'A' : %d, C'B'A : %d, C'BA' : %d, C'BA : %d, CB'A' : %d, CB'A : %d, CBA' : %d, CBA : %d", 
			(tbl >> 7) & 1, (tbl >> 6) & 1, (tbl >> 5) & 1, (tbl >> 4) & 1,
			(tbl >> 3) & 1, (tbl >> 2) & 1, (tbl >> 1) & 1, (tbl >> 0) & 1);
		return buff;
	}
}