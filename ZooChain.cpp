#include <iostream>
#include "ZooChain.h" //Including the header file
using namespace std;


void ZooChain::add_Cage(char *name,int cageNumber)
{
	if (start == NULL)
	{
		start = new ZooCage;
		start->name = name;
		start->cageNumber = cageNumber;
	}
	else
	{
		ZooCage* address = start;
		while (address != NULL)
		{
			if (address->link == NULL)
			{
				address->link = new ZooCage;
				break;
			}
			address = address->link;
		}
		address->link->name = name;
		address->link->cageNumber = cageNumber;
	}
}

void ZooChain::print_Chain()
{
	ZooCage* chain = start;
	for (int print = 1; chain != NULL; print++)
	{
		cout << chain->name << endl;
		cout << chain->cageNumber << endl;
		chain = chain->link;
	}
}

void ZooChain::delete_Chain( int cageNumber)
{
	int counter = 0;
	ZooCage* remove = start;
	ZooCage* temp = start;
	while (remove != NULL)
	{
		if (remove->cageNumber == cageNumber)
		{
			break;
		}
		remove = remove->link;
		counter++;
	}
	if (counter == 0)
	{
		start = start->link;
	}
	else
	{
		while (counter > 1)
		{
			temp = temp->link;
			counter--;
		}
		temp->link = remove->link;
		remove = NULL;
	}
}

void ZooChain::Sort_Chain()
{
	ZooCage* sort;
	int counter = 0;
	sort = start;
	while (sort != NULL)
	{
		sort = sort->link;
		counter++;
	}

	for (int repeat = 0; repeat < counter; repeat++)
	{
		sort = start;
		while (sort != NULL)
		{
			if (sort->link != NULL)
			{
				if (sort->link->cageNumber < sort->cageNumber)
				{
					char* temp = sort->link->name;
					sort->link->name = sort->name;
					sort->name = temp;
					int temp2 = sort->link->cageNumber;
					sort->link->cageNumber = sort->cageNumber;
					sort->cageNumber = temp2;
				}
			}
			sort = sort->link;
		}
	}
}

void ZooChain::remove_Duplicate()
{
	ZooCage* dupe = start;
	ZooCage* licate = start;
	ZooCage* temp = start;
	int counter = 0;
	bool repeat = false;
	while (dupe != NULL)
	{
		counter = 0;
		temp = start;
		licate = licate->link;
		while (licate != NULL)
		{
			if (dupe->name == licate->name)
			{
				repeat = true;
				break;
			}
			counter++;
			licate = licate->link;
		}
		if (repeat == true)
		{
			while (counter > 1)
			{
				temp = temp->link;
				counter--;
			}
			if (licate->link != NULL)
			{
				temp->link = licate->link;
				licate->link = NULL;
			}
			else
			{
				temp->link = NULL;
			}
			repeat = false;
		}
		dupe = dupe->link;
		licate = dupe;
	}
}

void ZooChain::update_name_at_cageNumber(int cageNumber, char* name)
{
	ZooCage* newName = start;
	while (newName != NULL)
	{
		if (newName->cageNumber == cageNumber)
		{
			newName->name = name;
		}
		newName = newName->link;
	}
}


ZooChain::~ZooChain()
{
	start = NULL;
}
