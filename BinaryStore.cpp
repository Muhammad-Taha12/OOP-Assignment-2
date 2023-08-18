#include <iostream>
#include "BinaryStore.h"
using namespace std;

BinaryStore::BinaryStore(int len = 0)
{
	size = len;
	library = new char*[len];
	for (int row = 0; row < len; row++)
	{
		library[row] = new char[9];
	}
	shelf = new char*[len];
	for (int row = 0; row < len; row++)
	{
		shelf[row] = new char[5];
		for (int col = 0; col < 4; col++)
		{
			shelf[row][col] = 'N';
		}
		shelf[row][4] = '\0';
	}
}

void BinaryStore::add_Address(char* s)
{
	int add = 0;
	bool match = false;
	while (add < size)
	{
		if (shelf[add][0] == 'N')
		{
			shelf[add] = s;
			match = true;
			break;
		}
		else if (shelf[add] == s)
		{
			match = true;
			break;
		}
		add++;
	}
	if (match == false)
	{
		shelf[size] = new char[5];
		shelf[size] = s;
		library[size] = new char[9];
		size++;
	}
}


void BinaryStore::set_Byte(char* address, char* value)
{
	add_Address(address);
	int find = 0;
	while (find < size)
	{
		if (shelf[find] == address)
		{
			library[find] = value;
		}
		find++;
	}
}

char* BinaryStore::Get(char* address)
{
	int get = 0;
	while (get < size)
	{
		if (address == shelf[get])
		{
			if (library[get][0] == '\0')
			{
				return NULL;
			}
			return library[get];
		}
		get++;
	}
	return NULL;
}


char* BinaryStore::ToString()
{
	int row = 0, col = 0, space = 0, fill = 0, row2 = 0;
	while(space < size)
	{
		if(library[row2][col] != NULL)
		{
			fill += 8;
		}
		row2++;
		col++;
		space++;
	}
	char* Store = new char[fill + 2];
	int loop = 0;
	col = 0;
	while (library[row] != NULL || library[row + 1] != NULL)
	{
		col = 0;
		if (library[row][col] != NULL)
		{
			while (library[row][col] != '\0')
			{
				Store[loop] = library[row][col];
				col++;
				loop++;
			}
		}
		row++;
		if (row == row2)
		{
			break;
		}
	}
	Store[fill + 1] = '\0';
	return Store;
}

char* BinaryStore::Add(char * a, char * b)
{
	int length = 0;
	while (a[length] != '\0')
	{
		length++;
	}
	char* Sum = new char[length + 1];
	int length2 = 0;
	while (length2 < length)
	{
		Sum[length2] = '0';
		length2++;
	}
	Sum[length + 1] = '\0';
	while (length >= 0)
	{
		if (a[length] == '0' && b[length] == '0' && Sum[length] == '0')
		{
			Sum[length] = '0';
		}
		else if ((a[length] == '0' && b[length] == '1' && Sum[length] == '0') || (a[length] == '1' && b[length] == '0' && Sum[length] == '0') || (a[length] == '0' && b[length] == '0' && Sum[length] == '1'))
		{
			Sum[length] = '1';
		}
		else if ((a[length] == '1' && b[length] == '1' && Sum[length] == '0') || (a[length] == '1' && b[length] == '0' && Sum[length] == '1') || (a[length] == '0' && b[length] == '1' && Sum[length] == '1'))
		{
			Sum[length] = '0';
			if (length != 0)
			{
				Sum[length - 1] = '1';
			}
		}
		else if (a[length] == '1' && b[length] == '1' && Sum[length] == '1')
		{
			Sum[length] = '1';
			if (length != 0)
			{
				Sum[length - 1] = '1';
			}
		}
		length--;
	}
	return Sum;
}

bool BinaryStore::comp_EQUAL(char* a, char *b)
{
	int length = 0, count = 0;
	while (a[length] != '\0')
	{
		if (a[length] == b[length])
		{
			count++;
		}
		length++;
	}
	if (count == length)
	{
		return true;
	}
	return false;
}

char* BinaryStore::comp_AND(char* a, char *b)
{
	int length = 0;
	while (a[length] != '\0')
	{
		length++;
	}
	char* AND = new char[length + 1];
	length = 0;
	while (a[length] != '\0')
	{
		if (a[length] == '1' && b[length] == '1')
		{
			AND[length] = '1';
		}
		else
		{
			AND[length] = '0';
		}
		length++;
	}
	AND[length] = '\0';
	return AND;
}

char* BinaryStore::comp_OR(char * a, char * b )
{
	int length = 0;
	while (a[length] != '\0')
	{
		length++;
	}
	char* OR = new char[length + 1];
	length = 0;
	while (a[length] != '\0')
	{
		if (a[length] == '0' && b[length] == '0')
		{
			OR[length] = '0';
		}
		else
		{
			OR[length] = '1';
		}
		length++;
	}
	OR[length] = '\0';
	return OR;
}
char* BinaryStore::comp_NOT(char * a)
{
	int length = 0;
	while (a[length] != '\0')
	{
		length++;
	}
	char* NOT = new char[length + 1];
	length = 0;
	while (a[length] != '\0')
	{
		if (a[length] == '0')
		{
			NOT[length] = '1';
		}
		else
		{
			NOT[length] = '0';
		}
		length++;
	}
	NOT[length] = '\0';
	return NOT;
}

BinaryStore::~BinaryStore()
{
	delete[] library;
	library = NULL;
	delete[] shelf;
	shelf = NULL;
}
