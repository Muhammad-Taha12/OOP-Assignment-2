#include<iostream>
#include"String.h"
using namespace std;

String::String(char* str)
{
	data = str;
}

String::String(const String & copy)
{
	int counter = 0;
	while (copy.data[counter] != '\0')
	{
		counter++;
	}
	data = new char[counter + 1];
	counter = 0;
	while (copy.data[counter] != '\0')
	{
		data[counter] = copy.data[counter];
		counter++;
	}
	data[counter] = '\0';
}

String::String(int x)
{
	data = new char[x];
}

char* String::getdata()
{
	return data;
}

char String::getChar(int i)
{
	return data[i];
}

bool String::isEmpty()
{
	if (*data == '\0')
	{
		return true;
	}
	return false;
}

int String::length()
{
	int length = 0;
	while (data[length] != '\0')
	{
		length++;
	}
	return length;
}

int String::index_at(char search) const
{
	int check = 0;
	while (data[check] != '\0')
	{
		if (data[check] == search)
		{
			return check;
		}
		check++;
	}
	return -1;
}

int String::index_at(const String& search) const
{
	int check = 0;
	while (data[check] != '\0')
	{
		if (data[check] == search.data[0])
		{
			return check;
		}
		check++;
	}
	return -1;
}

int String::index_at(const string& search) const
{
	int check = 0;
	while (data[check] != '\0')
	{
		if (data[check] == search[0] && data[check + 1] == search[1])
		{
			return check;
		}
		check++;
	}
	return -1;
}

int String::index_at(char* search) const
{
	int check = 0;
	while (data[check] != '\0')
	{
		if (data[check] == search[0] && data[check + 1] == search[1])
		{
			return check;
		}
		check++;
	}
	return -1;

}

bool String::isEqual(const String& equal) const
{
	int compare = 0, size = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	while (data[compare] == equal.data[compare] && data[compare] != '\0')
	{
		compare++;
	}
	if (compare == size)
	{
		return true;
	}
	return false;
}

bool String::isEqual(const string& equal) const
{
	int compare = 0, size = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	while (data[compare] == equal[compare] && data[compare] != '\0')
	{
		compare++;
	}
	if (compare == size)
	{
		return true;
	}
	return false;
}

bool String::isEqual(char* equal) const
{
	int compare = 0, size = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	while (data[compare] == equal[compare] && data[compare] != '\0')
	{
		compare++;
	}
	if (compare == size)
	{
		return true;
	}
	return false;
}

String String::append_string(const String &str)
{
	int add = 0, add2 = 0, size = 0, strsize = 0, totalsize = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	while (str.data[strsize] != '\0')
	{
		strsize++;
	}
	totalsize = size + strsize + 1;
	String newString = new char[totalsize];
	while (add <= size)
	{
		newString.data[add] = data[add];
		add++;
	}
	while (add2 <= strsize)
	{
		newString.data[size] = str.data[add2];
		size++;
		add2++;
	}
	newString.data[size] = '\0';
	data = newString.data;
	return newString;
}

String String::append_string(const char &str)
{
	int add = 0, size = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	String newString = new char[size + 2];
	while (add <= size)
	{
		newString.data[add] = data[add];
		add++;
	}
	newString.data[add - 1] = str;
	newString.data[add] = '\0';
	data = newString.data;
	return newString;
}
String String::append_string(char *&str)
{
	int add = 0, add2 = 0, size = 0, strsize = 0, totalsize = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	while (str[strsize] != '\0')
	{
		strsize++;
	}
	totalsize = size + strsize + 1;
	String newString = new char[totalsize];
	while (add <= size)
	{
		newString.data[add] = data[add];
		add++;
	}
	while (add2 <= strsize)
	{
		newString.data[size] = str[add2];
		size++;
		add2++;
	}
	newString.data[size] = '\0';
	data = newString.data;
	return newString;
}
String String::append_string(string& str)
{
	int add = 0, add2 = 0, size = 0, strsize = 0, totalsize = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	while (str[strsize] != '\0')
	{
		strsize++;
	}
	totalsize = size + strsize + 1;
	String newString = new char[totalsize];
	while (add <= size)
	{
		newString.data[add] = data[add];
		add++;
	}
	while (add2 <= strsize)
	{
		newString.data[size] = str[add2];
		size++;
		add2++;
	}
	newString.data[size] = '\0';
	data = newString.data;
	return newString;
}

String String::remove_string(const String &substr)
{
	int remove = 0, size = 0, size2 = 0, check = 0, count = 0;
	bool match = false;
	while (substr.data[size] != '\0')
	{
		size++;
	}
	while (data[size2] != '\0')
	{
		size2++;
	}
	while (data[remove] != '\0')
	{
		if (data[remove] == substr.data[0])
		{
			check = remove;
			while (data[check] == substr.data[count] && data[check] != '\0')
			{
				count++;
				check++;
			}
			if (count == size)
			{
				check = remove;
				match = true;
				break;
			}
		}
		remove++;
	}
	int count2 = count + check, copy = 0;
	String removedString = new char[size2 - size + 1];
	if (match == true)
	{
		while (data[count2] != '\0')
		{
			removedString.data[copy] = data[count2];
			count2++;
			copy++;
		}
	}
	copy = 0;
	while (removedString.data[copy] != '\0')
	{
		data[check] = removedString.data[copy];
		check++;
		copy++;
	}
	data[check] = '\0';
	return removedString;
}


String String::remove_string(string &substr)
{
	int remove = 0, size = 0, size2 = 0, check = 0, count = 0;
	bool match = false;
	while (substr[size] != '\0')
	{
		size++;
	}
	while (data[size2] != '\0')
	{
		size2++;
	}
	while (data[remove] != '\0')
	{
		if (data[remove] == substr[0])
		{
			check = remove;
			while (data[check] == substr[count] && data[check] != '\0')
			{
				count++;
				check++;
			}
			if (count == size)
			{
				check = remove;
				match = true;
				break;
			}
		}
		remove++;
	}
	int count2 = count + check, copy = 0;
	String removedString = new char[size2 - size + 1];
	if (match == true)
	{
		while (data[count2] != '\0')
		{
			removedString.data[copy] = data[count2];
			count2++;
			copy++;
		}
	}
	copy = 0;
	while (removedString.data[copy] != '\0')
	{
		data[check] = removedString.data[copy];
		check++;
		copy++;
	}
	data[check] = '\0';
	return removedString;
}

String String::remove_string(char *&substr)
{
	int remove = 0, size = 0, size2 = 0, check = 0, count = 0;
	bool match = false;
	while (substr[size] != '\0')
	{
		size++;
	}
	while (data[size2] != '\0')
	{
		size2++;
	}
	while (data[remove] != '\0')
	{
		if (data[remove] == substr[0])
		{
			check = remove;
			while (data[check] == substr[count] && data[check] != '\0')
			{
				count++;
				check++;
			}
			if (count == size)
			{
				check = remove;
				match = true;
				break;
			}
		}
		remove++;
	}
	int count2 = count + check, copy = 0;
	String removedString = new char[size2 - size + 1];
	if (match == true)
	{
		while (data[count2] != '\0')
		{
			removedString.data[copy] = data[count2];
			count2++;
			copy++;
		}
	}
	copy = 0;
	while (removedString.data[copy] != '\0')
	{
		data[check] = removedString.data[copy];
		check++;
		copy++;
	}
	data[check] = '\0';
	return removedString;
}

String String::remove_string(const char &chr)
{
	int remove = 0, size = 0, check = 0, count = 0;
	bool match = false;
	while (data[size] != '\0')
	{
		size++;
	}
	while (data[remove] != '\0')
	{
		if (data[remove] == chr)
		{
			check = remove;
			match = true;
			break;
		}
		remove++;
	}
	String removedString = new char[size];
	int count2 = check + 1;
	if (match == true)
	{
		while (data[count] != '\0')
		{
			removedString.data[count] = data[count2];
			count++;
			count2++;
		}
	}
	count = 0;
	while (removedString.data[count] != '\0')
	{
		data[check] = removedString.data[count];
		check++;
		count++;
	}
	data[check] = '\0';
	return removedString;
}

String& String::assign_string(const String& copy)
{
	int size = 0;
	while (copy.data[size] != '\0')
	{
		data[size] = copy.data[size];
		size++;
	}
	data[size] = '\0';
	return *this;
}

String& String::assign_string(char* copy)
{
	int size = 0;
	while (copy[size] != '\0')
	{
		data[size] = copy[size];
		size++;
	}
	data[size] = '\0';
	return *this;
}

String& String::assign_string(const string& copy)
{
	int size = 0;
	while (copy[size] != '\0')
	{
		data[size] = copy[size];
		size++;
	}
	data[size] = '\0';
	return *this;
}

String::~String()
{
	data = NULL;
}
