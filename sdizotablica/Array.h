#pragma once
class Array
{

private:

	int size;
	int *tab = new int[size]; //wskaünik na pierwszy element tablicy	

public:

	/*Konstruktory*/
	Array();
	Array(int i_key); 

	virtual ~Array(); //Destruktor

	void randomizeData();
	void loadFromFile(char url[]);				//Czytnik danych
	

	int getSize();
	
	void addElement(int i_value, int i_place);	//Dodaje element na okreslona pozycje
	void deleteElement(int i_value);			//Usuwa element z okreslonej pozycji
	void findElement(int i_value);				//Wyszukuje element o danej wartosci

	void writeArray();	//Wypisuje tablice
	
};


