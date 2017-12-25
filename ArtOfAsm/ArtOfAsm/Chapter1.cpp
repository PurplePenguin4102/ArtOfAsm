#include "stdafx.h"

namespace Chapter1
{
	char toUpper(char inp)
	{
		if (inp < 'a' || 'z' < inp)
		{
			return '\0';
		}
		// need to go from hex 6x to hex 4x
		// 6 == 0110, 4 == 0100
		// need to turn off bit 5 : 1101 1111 0xDF
		return inp & 0xDF;
	}

	char toLower(char inp)
	{
		if (inp < 'A' || 'Z' < inp)
		{
			return '\0';
		}
		// need to go from hex 4x to hex 6x
		// 6 == 0110, 4 == 0100
		// need to turn on bit 5 : 0010 0000 0x20
		return inp | 0x20;
	}

	int atoi(char* inp)
	{
		int acc = 0;
		for (int i = 0; inp[i] != '\0'; i++)
		{
			char numc = inp[i];
			if (numc < '0' || numc > '9')
			{
				return -1;
			}
			int num = numc & 0x0F;
			acc *= 10;
			acc += num;
		}
		return acc;
	}
	unsigned short toDate(unsigned int yr, unsigned int mo, unsigned int dd)
	{
		if (yr > 99 || mo > 12 || dd > 31)
		{
			return 0;
		}
		unsigned short code = 0;
		code += (mo << 12);
		code += (dd << 7);
		code += yr;
		return code;
	}

	int cntBits(unsigned short inp)
	{
		int acc = 0;
		for (int i = 0; i < 16; i++)
		{
			if (inp & (0x01 << i))
			{
				acc++;
			}
		}
		return acc;
	}

	bool testBit(unsigned short inp, unsigned short bit)
	{
		return (inp & (1 << bit)) > 0;
	}

	unsigned short rol(unsigned short inp)
	{
		int radix = testBit(inp, 15) ? 1 : 0;
		return (inp << 1) + radix;
	}

	unsigned short ror(unsigned short inp)
	{
		int radix = testBit(inp, 0) ? 0x8000 : 0;
		return (inp >> 1) + radix;
	}
}