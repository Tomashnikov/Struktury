#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <fstream>

using namespace std;


List::List(){
	size = 0;
}

List::List(int i_key) :head(NULL), tail(NULL), size(0)
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

void List::loadFromFile(char url[])
{
	fstream myfile;
	myfile.open(url, ios_base::in);

	int a, len = 0;
	while (myfile >> a)
	{
		addToFront(a);
	}

	myfile.close();
}

List::~List()
{
	while (!isEmpty()){
		delFromFront();
	}
}


bool List::isEmpty(){
	return size == 0;
}

void List::addToFront(int i_value){
	element* newHead = new element(i_value, head, NULL);
	
	if (isEmpty()){
		head = newHead;
		tail = newHead;
	}
	else{
		head->prev = newHead;
		head = newHead;
	}
	size++;
}

void List::addToBack(int i_value){
	element* newTail = new element(i_value, NULL,tail);
	if (isEmpty()){
		head = newTail;
	}
	else{
		tail->next = newTail;
	}
	tail = newTail;
	size++;
}

void List::addToPlace(int i_value, int i_place){
	element* newElement = new element(i_value, NULL, NULL);
	element* current = head;

	int x = 0;
	if (i_place == 0) addToFront(i_value);
	else if (i_place == size) addToBack(i_value);
	else {
		if (current != NULL){
			while (current->next != NULL && x < i_place){
				current = current->next;
				x++;
			}
			newElement->next = current-> next;
			newElement->prev = current;
			current->next->prev = newElement;
			current->next = newElement;
			
			size++;
		}
	}
}

void List::addAfterNumber(int i_target, int i_value){
	element* current = head;
	element* newElement = new element(i_value,NULL,NULL);
	bool isover = 0;

	if (current != NULL){
		while (current->next != NULL && isover == 0){
			current = current->next;
			if (current->value == i_target){
				newElement->next = current->next;
				newElement->prev = current;
				current->next->prev = newElement;
				current->next = newElement;

				isover = 1;
			}
		}
		if (!isover) addToFront(i_value);
		size++;
}
}

void List::delFromFront(){
	element* oldHead = head;
	if (size == 1){
		head = NULL;
		tail = NULL;
		}
	else{
		head = head->next;
		}
	oldHead = NULL;
	size--;
}

void List::delFromBack(){
	element* oldTail = tail;
	if (size == 1){
		head = NULL;
		tail = NULL;
	}
	else{
		tail = tail->prev;
	}
	delete oldTail;
	size--;
}

void List::delRandom(int i_value){
	element* current = head;
	int x = 0;
	if (i_value == 0) delFromFront();

	else {
		if (current != NULL){
			while (current->next != NULL && x < i_value){
				current = current->next;
				x++;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			
			size--;
		}
	}
	delete current;
}

void List::delSpecific(int i_value){

	element* current = head;
	if (i_value == head->value)  delFromFront(); 
	else if (i_value == tail->value) delFromBack(); 
	else{
		while (current->next != NULL){
			current = current->next;
			if (current->value == i_value){
				current->prev->next = current->next;
				current->next->prev = current->prev;	
			}
		}
		size--;
	}
	
}

void List::findValue(int i_value){
	element* current = head;

	if (current != NULL){
		while (current->next != NULL){
			if (current->value == i_value) cout << "Znaleziono w liscie liczbe " << i_value;
			current = current->next;
			break;
		}
	}
}



void List::writeList(){
	cout << endl << "Lista: " << endl;

	element* current = head;

	if (current != NULL){
		while (current->next != NULL){
			cout << current->value << " ";
			current = current->next;
			}
		cout << current->value << endl;
	}


}

void List::writeListfromBack(){
	cout << endl << "Lista od tylu: " << endl;

	element* current = tail;

	if (current != NULL){
		while (current->prev != NULL){
			cout << current->value << " ";
			current = current->prev;
		}
	cout << current->value << endl;
	}
}

int List::getSize()
{
	return size;
}