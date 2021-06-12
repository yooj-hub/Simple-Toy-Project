#include "List.h"
using namespace std;

template<class T>
List<T>::List()
{
	itemCount = 0;
	size = 5;
	items = new T [size];
}
template<class T>
List<T>::~List()
{
	delete[] items;
}

template<class T>
T List<T>::getItem(int index) {
	if (index > itemCount) {
		return -99999;
	}
	else
		return items[index];
}
template<class T>
void List<T>::addItem(T itm) {
	if (itemCount < size) {
		items[itemCount] = itm;
		itemCount++;
	}
	else
	{
		T* newItems = new T[size * 2];
		for (int i = 0; i < size; i++) {
			newItems[i] = items[i];
		}
		newItems[itemCount] = itm;
		itemCount++;
		delete[] items;
		items = newItems;
		size = size * 2;
	}
}
template<class T>
void List<T>::insertItem(int index, T itm) {
	T temp;
	T temp2;
	temp = items[index];
	items[index] = itm;
	addItem(items[itemCount - 1]);
	for (; index + 1 < itemCount - 1; index++) {
		temp2 = items[index + 1];
		items[index + 1] = temp;
		temp = temp2;
	}
}
template<class T>
int List<T>::removeAt(int index) {
	if (index > itemCount)
		return -99999;
	T k = items[index];

	for (; index < itemCount; index++)
	{
		items[index] = items[index + 1];
	}
	itemCount--;
	return k;
}
template<class T>
int List<T>::removeItm(T itm) {
	for (int i = 0; i < itemCount; i++) {
		if (items[i] == itm) {
			for (int j = i; j < itemCount; j++) {
				items[j] = items[j + 1];
			}
			itemCount--;
			return i;
		}
	}
	return -99999;
}
template<class T>
void List<T>::print() {
	for (int i = 0; i < itemCount; i++) {
		std::cout << items[i] << " ";
	}
	std::cout << std::endl;
}
template<class T>
void List<T>::operator+(List<T>& list) {
	for (int i = 0; i < list.itemCount; i++) {
		addItem(list.items[i]);
	}
}

template<class T>
int List<T>::getSize() {
	return size;
}
template<class T>
int List<T>::getItemCount() {
	return itemCount;
}
