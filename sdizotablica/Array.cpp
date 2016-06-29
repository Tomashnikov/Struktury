#include "stdafx.h"
#include "Array.h"
#include <iostream>
#include <fstream>

using namespace std;


Array::Array()
{
	size = 0;
}

Array::Array(int i_key)
{
	switch (i_key){
	case 100:
		loadFromFile("data/100.txt"); break;
	case 500:
		loadFromFile("data/500.txt"); break;
	case 1000:
		loadFromFile("data/1000.txt"); break;
	case 2000:
		loadFromFile("data/2000.txt"); break;
	case 5000:
		loadFromFile("data/5000.txt"); break;
	case 20000:
		loadFromFile("data/20000.txt"); break;
	}
	
}


void Array::loadFromFile(char url[])
{
	fstream myfile;
	myfile.open(url, ios_base::in);

	int a, len = 0;
	while (myfile >> a)
	{
		addElement(a,size);
	}
	myfile.close();
}

void Array::writeArray(){
	for (int x = 0; x < size; x++){
		cout << *(tab + x) << " ";
	}
	cout << endl;
}

Array::~Array()
{
	delete[] tab;
}

int Array::getSize()
{
	return size;
}

void Array::randomizeData()
{
	for (int x = 0; x < size; x++) tab[x] = rand() % 100;
}

void Array::addElement(int i_value, int i_place){
	size++;
		int *tab_t = new int[size];
		for (int x = 0, y = 0; x < size; x++){
		if (x == i_place){
			tab_t[x] = i_value;
			y++;
		}
		else{
    	tab_t[x] = tab[x-y];
		}
		
	}
	
	delete[] tab;
	tab = tab_t;
		
}

void Array::deleteElement(int i_value){

	size--;
	int *tab_t = new int[size];
	for (int x = 0, y = 0; x < size; x++){
		if (x != i_value)
		{
			tab_t[x] = tab[x+y];
		}
		else{
			y++; 
			tab_t[x] = tab[x + y];
		}
	}

	delete[] tab;
	tab = tab_t;
}

void Array::findElement(int i_value){
	int counter = 0;
	for (int x = 0; x < size; x++){
		if (tab[x] == i_value){
			cout << "Znaleziono wartosc " << i_value << " na pozycji " << x << endl;
			break;
		}
	}
}
