#pragma once
namespace Chapter2
{
	char loadTable(unsigned int i, unsigned int j, unsigned int k, unsigned int l);
	bool evaluate(char tbl, bool A, bool B);
	char* displayTbl4Bit(char tbl, char* buff);
	char* displayTbl8Bit(char tbl, char* buff);
}