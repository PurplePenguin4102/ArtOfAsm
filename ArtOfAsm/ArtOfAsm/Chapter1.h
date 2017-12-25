#pragma once
namespace Chapter1
{
	char toUpper(char inp);
	char toLower(char inp);
	int atoi(char* inp);
	unsigned short toDate(unsigned int yr, unsigned int mo, unsigned int dd);
	int cntBits(unsigned short inp);
	bool testBit(unsigned short inp, unsigned short bit);
	unsigned short ror(unsigned short inp);
	unsigned short rol(unsigned short inp);
}