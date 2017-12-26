// ArtOfAsm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chapter1.h"
#include "Chapter2.h"
int main()
{
	// Chapter 1-1 test code
	auto sol1 = Chapter1::toLower('A');
	auto sol2 = Chapter1::toUpper('b');
	sol1 = Chapter1::toUpper('k');
	sol2 = Chapter1::toLower('M');
	//
	// Chapter 1-2 test code
	auto blim = Chapter1::atoi("1234");
	//
	// Chapter 1-3 test code
	auto date = Chapter1::toDate(17, 03, 02);
	unsigned short mo = (date & 0xF000) >> 12;
	unsigned short dd = (date & 0x0F80) >> 7;
	unsigned short yr = date & 0x007F;
	//
	// Chapter 1-4 test code
	auto bitNum = Chapter1::cntBits(0xDF31);
	//
	// Chapter 1-5 test code
	auto tru = Chapter1::testBit(3, 1);
	//
	// Chapter 1-6 test code
	auto right = 1;
	auto left = 1;
	while (true)
	{
		right = Chapter1::ror(right);
		left = Chapter1::rol(left);
		if (left == right)
			break;
	}

	//---------------------------
	//
	// Chapter 2-1 test code
	auto tbl = Chapter2::loadTable(1, 0, 1, 1);
	auto trufa = Chapter2::evaluate(tbl, true, false);
	//
	// Chapter 2-2 test code
	auto disp = Chapter2::displayTbl4Bit(tbl);
	
	//
	// Chapter 2-3 test code
	auto disp2 = Chapter2::displayTbl8Bit(tbl);

    return 0;
}

