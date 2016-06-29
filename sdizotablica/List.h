#pragma once
class List
{

private:

	int size;

	//Deklaracja klasy element - Elementy Listy
	class element{
	private:
		friend class List;
		int value;
		element* next;	//Nastêpnik
		element* prev;	//Poprzednik
	public:

		//Konstruktor elementu
		element(int i_value, element* new_element = NULL, element* prev_element = NULL) : value(i_value), next(new_element),prev(prev_element){};

	};

	element *head;		//Front
	element *tail;		//Ogon

public:
	List();
	List(int i_key);
	List(const List &src);
	~List();

	void addToFront(int i_value);	//Dodaj do frontu listy
	void addToBack(int i_value);	//Dodaj do ty³u listy
	void addToPlace(int i_value, int i_place);	//Dodaj do wybranej pozycji listy
	void addAfterNumber(int i_target, int i_value);	//Dodaj po wybranej wartosci

	void delFromFront();		//Usuñ z frontu
	void delFromBack();			//Usuñ z koñca
	void delRandom(int i_value);	//Usuñ losowy
	void delSpecific(int i_value);	//Usuñ wybrany 

	void loadFromFile(char url[]);	//Czytnik danych
	void findValue(int i_value);	//Wyszukaj dan¹ wartoœæ
	
	void writeList();			//Wypisanie elementów listy
	void writeListfromBack();		
	

	bool isEmpty();	//czy jest pusty?
	int getSize();	//Assesor rozmiaru


};