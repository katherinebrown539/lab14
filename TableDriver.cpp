#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

void displayTitles(TableSortedList<CD>* s)
{
	ListDoublyLinkedIterator<CD>* i = s->iterator();
	
	while(i->hasNext())
	{
		i->next()->getKey()->displayString();
		cout << endl;
	}
}

void displayCDs(TableSortedList<CD>* s)
{
	ListDoublyLinkedIterator<CD>* i = s->iterator();
	
	while(i->hasNext())
	{
		i->next()->displayCD();
		cout << endl;
	}
}


int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   //DO THIS
   //thoroughly test your table
	for(int c = 0; c < num_items; c++)
	{
		slt->tableInsert(cds->get(c+1));
	}
	
	displayTitles(slt);





   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}