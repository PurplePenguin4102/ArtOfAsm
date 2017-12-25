#include "stdafx.h"

namespace Chapter2
{
	// returns encoded truth table
	// 0 0 0 0 B'A' B'A BA' BA
	char loadTable(int i, int j, int k, int l)
	{
		if (i > 2 || j > 2 || k > 2 || l > 2)
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

	}
}