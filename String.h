#ifndef STRING_H
#define STRING_H

class String
{
	char* data;
	// there is need of more data members, think about them...
	public:
		// provide definitions of following functions...
		String(); // default constructor
		String(char* str); // constructor9 String(char *str); // initializes the string with constant cstring
		String(const String &); // copy constructor to initialize the string from existing string
		String(int x); // initializes a string of pre-defined size
		char* getdata();
		char getChar(int i); // returns the character at index [x] in a string
		bool isEmpty(); // returns true if string is empty..

		String append_string(const String &str); // appends a String at the end of the String
		String append_string(const char &str); // appends a char at the end of the String
		String append_string(char *&str); // appends a String at the end of the String
		String append_string(string& str); // appends a String at the end of the String

		String remove_string(const String &substr); //removes the substr from the String
		String remove_string(string &substr); //removes the substr from the String
		String remove_string(char *&substr); //removes the substr from the String
		String remove_string(const char &chr); //removes the substr from the String

		String& assign_string(const String&); // copies one String to another
		String& assign_string(char*); // copies one c-string to another
		String& assign_string(const string&); // copies one string to another

		bool isEqual(const String&)const; //returns true if two Strings are equal
		bool isEqual(const string&)const; //returns true if two strings are equal
		bool isEqual(char *)const; //returns true if two strings are equal
		int index_at (char) const; // returns the index of the character being searched
		int index_at (const String&) const; // returns the start index of the String being searched
		int index_at (const string&) const; // returns the start index of the string being searched
		int index_at (char *) const; // returns the start index of the c-string being searched
		int length(); // returns the length of string
		~String(); // destructor...
};

#endif
