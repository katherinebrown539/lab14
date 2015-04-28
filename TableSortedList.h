#if !defined (TABLESORTEDLIST_H)
#define TABLESORTEDLIST_H

#include "SortedListDoublyLinked.h"

template < class T >
class TableSortedList
{

   private:
      SortedListDoublyLinked<T>* sldl;

   public:
      TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
      ~TableSortedList();

      bool tableIsEmpty();
      int tableSize();
      T* tableRetrieve(String* sk);
      void tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
      bool tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)

      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
TableSortedList<T>::TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item))
{
	sldl = new SortedListDoublyLinked<T>(comp_item, comp_key);
}

template < class T >
TableSortedList<T>::~TableSortedList()
{
	delete sldl;
}

template < class T >
bool TableSortedList<T>::tableIsEmpty()
{
	return sldl->isEmpty();
}

template < class T >
int TableSortedList<T>::tableSize()
{
	return sldl->size();
}

template < class T >
T* TableSortedList<T>::tableRetrieve(String* sk)
{
	T* item = NULL;
	item = sldl->get(sk);
	return item;
}

template < class T >
void TableSortedList<T>::tableInsert(T* item)   //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
{
	String* key = item->getKey();
	T* is_it_there = tableRetrieve(key);
	if(!is_it_there)
	{
		sldl->add(item);
	}
}

template < class T >
bool TableSortedList<T>::tableRemove(String* search_key)   //returns true if delete is successful (need to call tableRetrieve to see if the item is there)
{
	bool success = false;
	
	T* item_to_get_axe = tableRetrieve(search_key);
	if(item_to_get_axe == 0) return success;
	
	sldl->remove(search_key);
	success = true;
	
	return success;
}
template < class T >
ListDoublyLinkedIterator<T>* TableSortedList<T>::iterator()
{
	return sldl->iterator();
}









#endif