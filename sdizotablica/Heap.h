#pragma once
class Heap
{
private:

	int size;
	int *heap = new int[size];


public:
	Heap();	//Konstruktor domy�lny
	Heap(int i_size);	//Konstruktor po rozmiarze
	virtual ~Heap(); // Destruktor

	void randomizeData();	//Niepotrzebna funkcja losowania danych

	void addElement(int i_value);	//Dodaj element do stosu i napraw stos
	void deleteRoot();				//Usu� korze� stosu i napraw stos
	void findElement(int i_value);	//Znajd� element w stosie
	void loadFromFile(char url[]);	//Czytnik danych

	void writeHeap();		//Wypisanie stosu

	//Fixes - funkcje naprawy w g�r� i w d�
	void fixUp();	
	void fixDown();
	
};

