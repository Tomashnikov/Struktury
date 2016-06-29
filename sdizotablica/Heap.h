#pragma once
class Heap
{
private:

	int size;
	int *heap = new int[size];


public:
	Heap();	//Konstruktor domyœlny
	Heap(int i_size);	//Konstruktor po rozmiarze
	virtual ~Heap(); // Destruktor

	void randomizeData();	//Niepotrzebna funkcja losowania danych

	void addElement(int i_value);	//Dodaj element do stosu i napraw stos
	void deleteRoot();				//Usuñ korzeñ stosu i napraw stos
	void findElement(int i_value);	//ZnajdŸ element w stosie
	void loadFromFile(char url[]);	//Czytnik danych

	void writeHeap();		//Wypisanie stosu

	//Fixes - funkcje naprawy w górê i w dó³
	void fixUp();	
	void fixDown();
	
};

