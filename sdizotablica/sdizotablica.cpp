// sdizotablica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "List.h"
#include "RBT.h"
#include "Heap.h"
#include "Array.h"

using namespace std;

//Predeklaracje funkcji
void menuTablica();
void menuLista();
void menuKopiec();
void menuRBT();
void generateFiles(); 

//Funkcje pomiaru czasu
LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}



//Funkcja main()
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	
	//generateFiles(); //Wywo³anie generatora plików
	char pick = '0';


	//Menu G³ówne
	while (pick != 'Q'){
	
		
	cout << "Projekt 1 SDiZO - Tomasz Zachcial 218360" << endl;
	cout << "Wybierz z listy czynnosc wpisujac numer polecenia:" << endl << endl;
	cout << "1. Tablica" << endl << "2. Lista" << endl << "3. Stos" << endl << "4. Drzewo RBT" << endl << "Q. Exit" << endl;

	cin >> pick;

		switch (pick){
				{
				case '1':
					menuTablica();
					break;
				case '2':
					menuLista();
					break;
				case '3':
					menuKopiec();
					break;
				case '4':
					menuRBT();
					break;
				}
		}
	}
	return 0;
	}


	//Menu dla Tablicy
	void menuTablica(){
		LARGE_INTEGER performanceCountStart, performanceCountEnd;
		
		double tm;
		system("cls");
		Array *tab = new Array();
		
		int tmp1, tmp2;
		char key = '0';

		do{
			

			cout << "Wybierz z listy czynnosc wpisujac numer polecenia:" << endl << endl;
			cout << "0. Wczytaj tablice 100 elementow" << endl;
			cout << "1. Wczytaj tablice 500 elementow" << endl;
			cout << "2. Wczytaj tablice 1000 elementow" << endl;
			cout << "3. Wczytaj tablice 2000 elementow" << endl;
			cout << "4. Wczytaj tablice 5000 elementow" << endl;
			cout << "5. Wczytaj tablice 20000 elementow" << endl;
			cout << "6. Wyswietl elementy tablicy" << endl;
			cout << "7. Dodaj liczbe calkowita do tablicy" << endl;
			cout << "8. Usun wskazany element tablicy" << endl;
			cout << "9. Znajdz element w tablicy" << endl;
			cout << "B. Cofnij do menu glownego" << endl;

			cin >> key;

			switch (key){
			case '0':
				tab = new Array(100);
				break;
			case '1':
				tab = new Array(500);
				break;
			case '2':
				tab = new Array(1000);
				break;
			case '3':
				tab = new Array(2000);
				break;
			case '4':
				tab = new Array(5000);
				break;
			case '5':
				tab = new Array(20000);
				break;
			case '6':
				system("cls");
				tab->writeArray();
				break;
			case '7':

					system("cls");
					cout << "Podaj wartosc elementu dodawanego: " << endl;  cin >> tmp1;
					cout << endl << "Podaj pozycje na ktora ma byc dodany: 1 - pierwsza, 2 - ostatnia, 3 - losowa, 4 - wlasna" << endl;  cin >> tmp2;
					switch (tmp2){
					case 1:
						performanceCountStart = startTimer();	
							tab->addElement(tmp1,0);	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					case 2:
						performanceCountStart = startTimer();
							tab->addElement(tmp1,tab->getSize());	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					case 3:
						performanceCountStart = startTimer();
							tab->addElement(tmp1,rand()%(tab->getSize()-1));	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					case 4: 
							cout << "Podaj indeks pozycji: "; cin >> tmp2;

						performanceCountStart = startTimer();
							tab->addElement(tmp1, tmp2);	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;

						break;
					}
					break;

			case '8':

					system("cls");
					cout << endl << "Podaj ktory element usunac: 1 - pierwszy, 2 - ostatni, 3 - losowy, 4 - wlasny" << endl;  cin >> tmp1;
					switch (tmp1){
					case 1:
						performanceCountStart = startTimer();
							tab->deleteElement(0);	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					case 2:
						performanceCountStart = startTimer();
							tab->deleteElement(tab->getSize()-1);	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					case 3:
						performanceCountStart = startTimer();
							tab->deleteElement(rand()%(tab->getSize()-1));	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					case 4:
						cout << "Podaj indeks pozycji: "; cin >> tmp2;
						performanceCountStart = startTimer();
							tab->deleteElement(tmp2);	//f. w³aœciwa
						performanceCountEnd = endTimer();
						tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
						cout << endl << "Time: " << tm << endl;
						break;
					}
					break;

			case '9':
				cout << "Podaj wartosc elementu ktory mam znalezc: " << endl; cin >> tmp1;
				performanceCountStart = startTimer();
					tab->findElement(tmp1);	//f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			}
		}while (key!='B');

		delete tab;
	}

	//Menu dla listy
	void menuLista(){
		LARGE_INTEGER performanceCountStart, performanceCountEnd;
		double tm;
		List *list = new List();
		system("cls");
		int tmp1, tmp2;
		char key = '0';

		do{

			

			cout << "Wybierz z listy czynnosc wpisujac numer polecenia:" << endl << endl;
			cout << "0. Wczytaj liste 100 elementow" << endl;
			cout << "1. Wczytaj liste 500 elementow" << endl;
			cout << "2. Wczytaj liste 1000 elementow" << endl;
			cout << "3. Wczytaj liste 2000 elementow" << endl;
			cout << "4. Wczytaj liste 5000 elementow" << endl;
			cout << "5. Wczytaj liste 20000 elementow" << endl;
			cout << "6. Wyswietl elementy listy od frontu" << endl;
			cout << "7. Dodaj liczbe calkowita do listy" << endl;
			cout << "8. Usun wskazany element z listy" << endl;
			cout << "9. Znajdz element w liscie" << endl;
			cout << "B. Cofnij do menu glownego" << endl;

			cin >> key;

			switch (key){
			case '0':
				list = new List(100);
				break;
			case '1':
				list = new List(500);
				break;
			case '2':
				list = new List(1000);
				break;
			case '3':
				list = new List(2000);
				break;
			case '4':
				list = new List(5000);
				break;
			case '5':
				list = new List(20000);
				break;
			case '6':
				system("cls");
				list->writeList();
				break;
			case '7':

				system("cls");
				cout << "Podaj wartosc ktora mam dodac do listy: ";  cin >> tmp1;
				cout << endl << "Podaj pozycje na ktora dodac element listy: 1 - pierwsza, 2 - ostatnia, 3 - losowa, 4 - za wartoscia" << endl;  cin >> tmp2;
				switch (tmp2){
				case 1:
					performanceCountStart = startTimer();
						list->addToFront(tmp1); //f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;

				case 2:
					performanceCountStart = startTimer();
						list->addToBack(tmp1); //f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				case 3:
					performanceCountStart = startTimer();
						list->addToPlace(tmp1, rand() % list->getSize()); //f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				case 4:
					performanceCountStart = startTimer();
					cout << "Podaj wartosc, po ktorej dodana zostanie nowa wartosc: "; cin >> tmp2;
						list->addAfterNumber(tmp2, tmp1); //f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				}
				break;
			
			case '8':

				system("cls");
				cout << endl << "Podaj pozycje z ktorej usunac element listy: 1 - pierwsza, 2 - ostatnia, 3 - losowa, 4 - po wartosci" << endl;  cin >> tmp1;
				switch (tmp1){
				case 1:
					performanceCountStart = startTimer();
						list->delFromFront();	//f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				case 2:
					performanceCountStart = startTimer();
						list->delFromBack();	//f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				case 3:
					performanceCountStart = startTimer();
						list->delRandom(rand() % list->getSize());	//f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				case 4:
					performanceCountStart = startTimer();
					cout << "Podaj wartosc do odnalezienia i usuniecia "; cin >> tmp2;
						list->delSpecific(tmp2);	//f. w³aœciwa
					performanceCountEnd = endTimer();
					tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
					cout << endl << "Time: " << tm << endl;
					break;
				}
				break;

			case '9':
				system("cls");
				cout << "Podaj wartosc elementu ktory mam wyszukac: " << endl;  cin >> tmp1;
				performanceCountStart = startTimer();
				list->findValue(tmp1); //f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
			}
		} while (key != 'B');
		delete list;
	}
	
	//Menu dla kopca
	void menuKopiec(){
		LARGE_INTEGER performanceCountStart, performanceCountEnd;
		double tm;
		system("cls");
		Heap *heap = new Heap();
		int tmp1;
		char key = '0';
		
		do{

			

			cout << "Wybierz z listy czynnosc wpisujac numer polecenia:" << endl << endl;
			cout << "0. Wczytaj kopiec 100 elementow" << endl;
			cout << "1. Wczytaj kopiec 500 elementow" << endl;
			cout << "2. Wczytaj kopiec 1000 elementow" << endl;
			cout << "3. Wczytaj kopiec 2000 elementow" << endl;
			cout << "4. Wczytaj kopiec 5000 elementow" << endl;
			cout << "5. Wczytaj kopiec 20000 elementow" << endl;
			cout << "6. Wyswietl elementy kopca od gory" << endl;
			cout << "7. Dodaj liczbe calkowita do kopca" << endl;
			cout << "8. Usun korzen (root) kopca" << endl;
			cout << "9. Wyszukaj wartosc w kopcu" << endl;
			cout << "B. Cofnij do menu glownego" << endl;

			cin >> key;

			switch (key){
			case '0':
				heap = new Heap(100);
				break;
			case '1':
				heap = new Heap(500);
				break;
			case '2':
				heap = new Heap(1000);
				break;
			case '3':
				heap = new Heap(2000);
				break;
			case '4':
				heap = new Heap(5000);
				break;
			case '5':
				heap = new Heap(20000);
				break;
			case '6':
				system("cls");
					heap->writeHeap();
				break;
			case '7':
				system("cls");
				
				cout << "Podaj wartosc elementu dodawanego do kopca: " << endl;  cin >> tmp1;
				performanceCountStart = startTimer();
					heap->addElement(tmp1); //f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			case '8':
				performanceCountStart = startTimer();
					heap->deleteRoot();		//f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			case '9':
				performanceCountStart = startTimer();
				cout << "Podaj wartosc do wyszukania: " << endl;  cin >> tmp1;
				heap->findElement(tmp1);	//f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			}
		} while (key != 'B');
		delete heap;
	}

	//Menu dla drzewa RB
	void menuRBT(){

		LARGE_INTEGER performanceCountStart, performanceCountEnd;
		double tm;
		system("cls");
		RBTree *rbt = new RBTree();
		int tmp1;
		char key = '0';

		do{

		

			cout << "Wybierz z listy czynnosc wpisujac numer polecenia:" << endl << endl;
			cout << "0. Wczytaj drzewo 100 elementow" << endl;
			cout << "1. Wczytaj drzewo 500 elementow" << endl;
			cout << "2. Wczytaj drzewo 1000 elementow" << endl;
			cout << "3. Wczytaj drzewo 2000 elementow" << endl;
			cout << "4. Wczytaj drzewo 5000 elementow" << endl;
			cout << "5. Wczytaj drzewo 20000 elementow" << endl;
			cout << "6. Wyswietl elementy drzewa" << endl;
			cout << "7. Dodaj liczbe calkowita do drzewa" << endl;
			cout << "8. Usun liczbe calkowita z drzewa" << endl;
			cout << "9. Wyszukaj wartosc w drzewie" << endl;
			cout << "B. Cofnij do menu glownego" << endl;

			cin >> key;

			switch (key){
			case '0':
				rbt = new RBTree(100);
				break;
			case '1':
				rbt = new RBTree(500);
				break;
			case '2':
				rbt = new RBTree(1000);
				break;
			case '3':
				rbt = new RBTree(2000);
				break;
			case '4':
				rbt = new RBTree(5000);
				break;
			case '5':
				rbt = new RBTree(20000);
				break;
			case '6':
				system("cls");
				rbt->printRBT(rbt->root);
				break;
			case '7':
				system("cls");
				cout << "Podaj wartosc elementu dodawanego do drzewa: " << endl;  cin >> tmp1;
				performanceCountStart = startTimer();
					rbt->insertRBT(tmp1); //f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			case '8':
				cout << "Podaj wartosc elementu usuwanego z drzewa: " << endl;  cin >> tmp1;
				performanceCountStart = startTimer();
					rbt->removeRBT(rbt->findElement(tmp1)); //f. w³aœciwa
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			case '9':
				cout << "Podaj wartosc do wyszukania: " << endl;  cin >> tmp1;
				//f. w³aœciwa
				performanceCountStart = startTimer();
					if (rbt->findElement(tmp1)){
						cout << "Znaleziono element o wartosci: " << tmp1 << endl;
					}
					else{
						cout << "Nie znaleziono elementu o wartosci: " << tmp1 << endl;
					}
				performanceCountEnd = endTimer();
				tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time: " << tm << endl;
				break;
			}
		} while (key != 'B');
		delete rbt;
	}

	//Generator plików danych
	void generateFiles(){

		ofstream myfile("../Debug/data/100.txt");
		ofstream myfile2("../Debug/data/500.txt");
		ofstream myfile3("../Debug/data/1000.txt");
		ofstream myfile4("../Debug/data/2000.txt");
		ofstream myfile5("../Debug/data/5000.txt");
		ofstream myfile6("../Debug/data/20000.txt");

		if (myfile.is_open())
		{
			for (int x = 0; x < 100; x++){
			myfile << rand()%1000;
			myfile << "\n";
			}
			myfile.close();
		}

	

		if (myfile2.is_open())
			{
			for (int x = 0; x < 500; x++){
				myfile2 << rand() % 1000;
				myfile2 << "\n";
			}
			myfile2.close();
			}

	

		if (myfile3.is_open())
		{
			for (int x = 0; x < 1000; x++){
				myfile3 << rand() % 1000;
				myfile3 << "\n";
			}
			myfile3.close();
		}


		if (myfile4.is_open())
		{
			for (int x = 0; x < 2000; x++){
				myfile4 << rand() % 1000;
				myfile4 << "\n";
			}
			myfile4.close();
		}

		if (myfile5.is_open())
		{
			for (int x = 0; x < 5000; x++){
				myfile5 << rand() % 1000;
				myfile5 << "\n";
			}
			myfile5.close();
		}

		if (myfile6.is_open())
		{
			for (int x = 0; x < 20000; x++){
				myfile6 << rand() % 1000;
				myfile6 << "\n";
			}
			myfile5.close();
		}
	}