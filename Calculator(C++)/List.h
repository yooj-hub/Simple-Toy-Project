#pragma once
#include<iostream>
template <class T>
class List
{
private:
	T* items;
	int itemCount;
	int size;
public:
	List();
	~List();
	T getItem(int index);
	void addItem(T itm);
	void insertItem(int index, T itm);
	int getItemCount();
	int removeAt(int index);
	int removeItm(T itm);
	int getSize();
	void print();
	void operator+(List<T>& list);
};
