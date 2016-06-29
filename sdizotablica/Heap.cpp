#include "stdafx.h"
#include "Heap.h"
#include <iostream>
#include <fstream>

using namespace std;

Heap::Heap()
{
	size = 0;
}


Heap::Heap(int i_key)
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

Heap::~Heap()
{
	delete[] heap;
}

void Heap::loadFromFile(char url[]){
	fstream myfile;
	myfile.open(url, ios_base::in);

	int a, len = 0;
	while (myfile >> a)
	{
		addElement(a);
	}
	myfile.close();
}


void Heap::writeHeap(){
	for (int x = 0; x < size; x++){
		cout << *(heap + x) << " ";
	}
	cout << endl;
}

void Heap::addElement(int i_value)
{
	size++;
		int *heap_t = new int[size];
		for (int x = 0; x < size; x++){
			heap_t[x] = heap[x];
		}
		heap_t[size - 1] = i_value;
		
		delete[] heap;
		heap = heap_t;

		fixUp();
}

void Heap::randomizeData(){
	for (int x = 0; x < size; x++) {
		heap[x] = rand() % 100;
		fixUp();
	}
}

void Heap::fixUp(){
	int x = size - 1;
	int tmp;
	while (heap[x]>heap[(x - 1) / 2]){
		tmp = heap[(x-1)/2];
		heap[(x - 1) / 2] = heap[x];
		heap[x] = tmp;
		x = (x - 1) / 2;
	};
}

void Heap::fixDown(){
	int x = 0, tmp;
	while ((heap[x] < heap[2 * x + 1] && 2 * x + 1 <= size - 1) || (heap[x] < heap[2 * x + 2] && 2 * x + 2 <= size - 1)) {
		if (heap[2 * x + 1] >= heap[2 * x + 2]){
			tmp = heap[2*x+1];
			heap[2*x+1] = heap[x];
			heap[x] = tmp;
			
			x = 2 * x + 1;
		}
		else{
			tmp = heap[2 * x + 2];
			heap[2 * x + 2] = heap[x];
			heap[x] = tmp;
			x = 2 * x + 2;
		}
	};
}

void Heap::deleteRoot(){
	heap[0] = heap[size-1];
	size--;

	int *heap_t = new int[size];
	for (int x = 0; x < size; x++){
			heap_t[x] = heap[x];
	}

	delete[] heap;
	heap = heap_t;

	fixDown();


}

void Heap::findElement(int i_value){
	for (int x = 0; x < size; x++){
		if (heap[x] == i_value) cout << "Znaleziono wartosc " << i_value << " na pozycji " << x << " stosu" << endl;
	}
}