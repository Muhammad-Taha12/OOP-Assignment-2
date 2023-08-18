#include <iostream>
#include <fstream>
#include "Record.h"
using namespace std;

Record::Record(char* str)
{
	int size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	fileName = new char[size + 1];
	size = 0;

	while (str[size] != '\0')
	{
		fileName[size] = str[size];
		size++;
	}
	fileName[size] = '\0';

	ifstream Check;
	Check.open(fileName);
	if (!Check)
	{
		ofstream Store;
		Store.open(fileName);
		Store.close();
	}
	Check.close();
}

int Record::record_Input()
{
	char name[100] = "", address[100] = "", age[100] = "", CGPA[100] = "";
	cout << "Enter the name of the student: ";
	cin.ignore();
	cin.getline(name, 100);
	cout << "Enter the address of the student: ";
	cin.getline(address, 100);
	cout << "Enter the age of the student: ";
	cin.getline(age, 100);
	cout << "Enter the CGPA of the student: ";
	cin.getline(CGPA, 100);

	ofstream Write(fileName, ios::app);
	Write << "Name: " << name << '\n';
	Write << "Address: " << address << '\n';
	Write << "Age: " << age << '\n';
	Write << "CGPA: " << CGPA << '\n' << '\n';
	Write.close();
	return 0;
}

void Record::record_Display()
{
	char hold[1000] = "";

	ifstream Read(fileName);
	if (Read.is_open())
	{
		while (Read.getline(hold, 1000))
		{
				cout << hold << endl;
		}
	}
	Read.close();
}

int Record::delete_Record()
{
	int check = 0, count = 0, size = 0, match = 0, all = 0, sub = 0;
	bool found = false;
	char remove[1000] = "";
	char part[100] = "";
	char name[100] = "Name: ";
	char data[1000] = "";
	cout << "Choose student whose data you want to delete: ";
	cin.ignore();
	cin.getline(part, 100);
	for (int full = 0; part[full] != '\0'; full++)
	{
		name[6 + full] = part[full];
	}
	while (name[size] != '\0')
	{
		size++;
	}

	ifstream Read(fileName);
	if (Read.is_open())
	{
		while(Read.getline(remove, 1000))
		{
			check = 0;
			while (remove[check] != '\0')
			{
				if (match == 0)
				{
					if (remove[check] == name[count])
					{
						count++;
						found = true;
					}
					else if (remove[check] != name[count])
					{
						count = 0;
						found = false;
					}
					if (count == size && found == true && remove[check + 1] == '\0')
					{
						match++;
					}
				}
				if (match == 0 || match > 4)
				{
					data[all] = remove[check];
					all++;
				}
				else if (match == 1)
				{
					sub = check;
					while(sub >= -1)
					{
						data[all] = '\0';
						all--;
						sub--;
					}
				}
				check++;
			}
			if (match != 0)
			{
				match++;
			}
			if (match == 0 || match > 4)
			{
				data[all] = '\n';
				all++;
			}
		}
	}
	Read.close();

	if (found == false)
	{
		cout << "Student record does not exist" << endl << endl;
		return -1;
	}
	else
	{
		ofstream Write(fileName, ios::out);
		Write << data;
		Write.close();
	}
	return 0;
}



int Record::record_Count()
{
	int searchNum = 0;
	char count[1000] = "";
	ifstream Read(fileName);
	if (Read.is_open())
	{
		while(Read.getline(count, 1000))
		{
			if (count[0] == 'N')
			{
				searchNum++;
			}
		}
	}
	return searchNum;
}

int Record::record_Search()
{
	int recordNum = 0, check = 0, size = 0, match = 0, all = 0, sub = 0, counter = 0, fill = 0;
	char count[1000] = "";
	char find[100] = "";
	char data[1000] = "";
	bool found = false;
	cout << "Enter the name of the student you want to search for: ";
	cin.ignore();
	cin.getline(find, 100);
	while (find[size] != '\0')
	{
		size++;
	}

	ifstream Read(fileName);
	if (Read.is_open())
	{
		while(Read.getline(count, 1000))
		{
			if (found == false)
			{
				if (count[0] == 'N')
				{
					check = 0;
					all = 0;
					fill = 0;
					while (check < 6)
					{
						data[fill] = count[check];
						fill++;
						check++;
					}
					while (count[check] != '\0')
					{
						if (count[check] == find[all])
						{
							data[fill] = count[check];
							fill++;
							counter++;
						}
						else if (count[check] != find[all])
						{
							while (fill >= 0)
							{
								data[fill] = '\0';
								fill--;
							}
							counter = 0;
						}
						if (counter == size && count[check + 1] == '\0')
						{
							found = true;
							break;
						}
						all++;
						check++;
					}
					recordNum++;
				}
			}
			else if (found == true && match < 3)
			{
				data[fill] = '\n';
				fill++;
				check = 0;
				while (count[check] != '\0')
				{
					data[fill] = count[check];
					check++;
					fill++;
				}
				match++;
			}
		}
	}
	Read.close();

	if (found == false)
	{
		cout << "Student record wasnt found" << endl << endl;
		return -1;
	}
	else
	{
		cout << "Student record found at record number: " << recordNum << endl << endl;
		cout << data << endl;
	}
	return recordNum;
}

int Record::record_Insert()
{
	int recordNum = 0, check = 0, size = 0, match = 0, all = 0, sub = 0, counter = 0, fill = 0;
	char count[1000] = "";
	char find[100] = "";
	char data[1000] = "";
	bool found = false;
	cout << "Enter the name of the student you want to insert after: ";
	cin.ignore();
	cin.getline(find, 100);
	while (find[size] != '\0')
	{
		size++;
	}

	ifstream Read(fileName);
	if (Read.is_open())
	{
		while(Read.getline(count, 1000))
		{
			if (found == true)
			{
				match++;
			}
			if (match == 5)
			{
				int add = 0, sec = 0;
				char name[100] = "", address[100] = "", age[100] = "", CGPA[100] = "";
				cout << "Enter the name of the student: ";
				cin.getline(name, 100);
				data[fill] = '\n';
				fill++;
				data[fill] = 'N';
				fill++;
				data[fill] = 'a';
				fill++;
				data[fill] = 'm';
				fill++;
				data[fill] = 'e';
				fill++;
				data[fill] = ':';
				fill++;
				data[fill] = ' ';
				fill++;
				while (name[add] != '\0')
				{
					data[fill] = name[add];
					fill++;
					add++;
				}
				data[fill] = '\n';
				fill++;
				add = 0;
				cout << "Enter the address of the student: ";
				cin.getline(address, 100);
				data[fill] = 'A';
				fill++;
				data[fill] = 'd';
				fill++;
				data[fill] = 'd';
				fill++;
				data[fill] = 'r';
				fill++;
				data[fill] = 'e';
				fill++;
				data[fill] = 's';
				fill++;
				data[fill] = 's';
				fill++;
				data[fill] = ':';
				fill++;
				data[fill] = ' ';
				fill++;
				while (address[add] != '\0')
				{
					data[fill] = address[add];
					fill++;
					add++;
				}
				data[fill] = '\n';
				fill++;
				add = 0;
				cout << "Enter the age of the student: ";
				cin.getline(age, 100);
				data[fill] = 'A';
				fill++;
				data[fill] = 'g';
				fill++;
				data[fill] = 'e';
				fill++;
				data[fill] = ':';
				fill++;
				data[fill] = ' ';
				fill++;
				while (age[add] != '\0')
				{
					data[fill] = age[add];
					fill++;
					add++;
				}
				data[fill] = '\n';
				fill++;
				add = 0;
				cout << "Enter the CGPA of the student: ";
				cin.getline(CGPA, 100);
				data[fill] = 'C';
				fill++;
				data[fill] = 'G';
				fill++;
				data[fill] = 'P';
				fill++;
				data[fill] = 'A';
				fill++;
				data[fill] = ':';
				fill++;
				data[fill] = ' ';
				fill++;
				while (CGPA[add] != '\0')
				{
					data[fill] = CGPA[add];
					fill++;
					add++;
				}
				data[fill] = '\n';
				fill++;
				add = 0;
			}
			if (count[0] == 'N')
			{
				check = 6;
				all = 0;
				while (count[check] != '\0')
				{
					if (count[check] == find[all])
					{
						counter++;
					}
					else if (count[check] != find[all])
					{
						counter = 0;
					}
					if (counter == size && count[check + 1] == '\0')
					{
						found = true;
						match++;
						break;
					}
					all++;
					check++;
				}
				recordNum++;
			}
			check = 0;
			while (count[check] != '\0')
			{
				data[fill] = count[check];
				fill++;
				check++;
			}
			data[fill] = '\n';
			fill++;
		}
	}
	Read.close();
	if (found == false)
	{
		cout << "Name doesn't exist in the record" << endl << endl;
		return -1;
	}
	else
	{
		ofstream Write(fileName, ios::out);
		Write << data;
		Write.close();
	}
	return 0;
}

void Record::record_Replace()
{
	int check = 0, count = 0, size = 0, match = 0, all = 0, sub = 0, fill = 0;
	bool found = false;
	char remove[1000] = "";
	char part[100] = "";
	char name[100] = "Name: ";
	char data[1000] = "";
	cout << "Choose student whose data you want to replace: ";
	cin.ignore();
	cin.getline(part, 100);
	for (int full = 0; part[full] != '\0'; full++)
	{
		name[6 + full] = part[full];
	}
	while (name[size] != '\0')
	{
		size++;
	}

	ifstream Read(fileName);
	if (Read.is_open())
	{
		while(Read.getline(remove, 1000))
		{
			check = 0;
			while (remove[check] != '\0')
			{
				if (match == 0)
				{
					if (remove[check] == name[count])
					{
						count++;
						found = true;
					}
					else if (remove[check] != name[count])
					{
						count = 0;
						found = false;
					}
					if (count == size && found == true && remove[check + 1] == '\0')
					{
						match++;
					}
				}
				if (match == 0 || match > 4)
				{
					data[fill] = remove[check];
					fill++;
				}
				else if (match == 1)
				{
					sub = check;
					while(sub >= 0)
					{
						data[fill] = '\0';
						fill--;
						sub--;
					}
					int add = 0, sec = 0;
					char name[100] = "", address[100] = "", age[100] = "", CGPA[100] = "";
					cout << "Enter the name of the student: ";
					cin.getline(name, 100);
					data[fill] = '\n';
					fill++;
					data[fill] = 'N';
					fill++;
					data[fill] = 'a';
					fill++;
					data[fill] = 'm';
					fill++;
					data[fill] = 'e';
					fill++;
					data[fill] = ':';
					fill++;
					data[fill] = ' ';
					fill++;
					while (name[add] != '\0')
					{
						data[fill] = name[add];
						fill++;
						add++;
					}
					data[fill] = '\n';
					fill++;
					add = 0;
					cout << "Enter the address of the student: ";
					cin.getline(address, 100);
					data[fill] = 'A';
					fill++;
					data[fill] = 'd';
					fill++;
					data[fill] = 'd';
					fill++;
					data[fill] = 'r';
					fill++;
					data[fill] = 'e';
					fill++;
					data[fill] = 's';
					fill++;
					data[fill] = 's';
					fill++;
					data[fill] = ':';
					fill++;
					data[fill] = ' ';
					fill++;
					while (address[add] != '\0')
					{
						data[fill] = address[add];
						fill++;
						add++;
					}
					data[fill] = '\n';
					fill++;
					add = 0;
					cout << "Enter the age of the student: ";
					cin.getline(age, 100);
					data[fill] = 'A';
					fill++;
					data[fill] = 'g';
					fill++;
					data[fill] = 'e';
					fill++;
					data[fill] = ':';
					fill++;
					data[fill] = ' ';
					fill++;
					while (age[add] != '\0')
					{
						data[fill] = age[add];
						fill++;
						add++;
					}
					data[fill] = '\n';
					fill++;
					add = 0;
					cout << "Enter the CGPA of the student: ";
					cin.getline(CGPA, 100);
					data[fill] = 'C';
					fill++;
					data[fill] = 'G';
					fill++;
					data[fill] = 'P';
					fill++;
					data[fill] = 'A';
					fill++;
					data[fill] = ':';
					fill++;
					data[fill] = ' ';
					fill++;
					while (CGPA[add] != '\0')
					{
						data[fill] = CGPA[add];
						fill++;
						add++;
					}
					add = 0;
				}
				check++;
			}
			if (match != 0)
			{
				match++;
			}
			if (match == 0 || match > 4)
			{
				data[fill] = '\n';
				fill++;
			}
		}
	}
	Read.close();

	cout << data;

	if (found == false)
	{
		cout << "Student record does not exist" << endl << endl;
	}
	else
	{
		ofstream Write(fileName, ios::out);
		Write << data;
		Write.close();
	}
}

Record::~Record()
{
	fileName = NULL;
}

int main()
{
	char* filename = "Record.txt";
	Record Info(filename);
	char choice = ' ';
	while (choice != '8')
	{
		cout << "What do you want to do?" << endl;
		cout << "1 - Input a new Record" << endl;
		cout << "2 - Delete an existing Record" << endl;
		cout << "3 - Count the number of Records" << endl;
		cout << "4 - Search for an existing Record" << endl;
		cout << "5 - Insert a Record after another Record" << endl;
		cout << "6 - Replace an existing Record" << endl;
		cout << "7 - Display the Records" << endl;
		cout << "8 - End the Program" << endl;
		cin >> choice;
		switch (choice)
		{
			case '1':
				Info.record_Input();
				break;
			case '2':
				Info.delete_Record();
				break;
			case '3':
				cout << "The number of Records are: " << Info.record_Count() << endl;
				break;
			case '4':
				Info.record_Search();
				break;
			case '5':
				Info.record_Insert();
				break;
			case '6':
				Info.record_Replace();
				break;
			case '7':
				Info.record_Display();
				break;
			case '8':
				break;
			default:
				cout << "Invalid Option" << endl;
		}
	}
}
