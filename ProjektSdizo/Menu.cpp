#include<conio.h>
#include<string>
#include<iostream>
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "Array.h"
#include <random>
#include "BinarySearchTree.h"
#include <windows.h>
#include <iomanip>
#include <limits>
#include <fstream>
#include <math.h>
#include <string>
#include <list>

#undef max


using namespace std;


long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return((long long int)count.QuadPart);
}

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun z poczatku" << endl;
	cout << "3.Usun na koncu" << endl;
	cout << "4.Usun w losowym miejscu" << endl;
	cout << "5.Dodaj na poczatku" << endl;
	cout << "6.Dodaj na koncu" << endl;
	cout << "7.Dodaj w losowym miejscu" << endl;
	cout << "8.Utworz losowo" << endl;
	cout << "9.Znajdz wartosc" << endl;
	cout << "10.Wyswietl" << endl;
	cout << "11.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje: ";
}

void displayHeap(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun ze szczytu" << endl;
	cout << "3.Dodaj wartosc" << endl;
	cout << "4.Utworz losowo" << endl;
	cout << "5.Znajdz wartosc" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje: ";
}

void displayBST(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun wartosc" << endl;
	cout << "3.Dodaj wartosc" << endl;
	cout << "4.Utworz losowo" << endl;
	cout << "5.Znajdz wartosc" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Algorytm DSW" << endl;
	cout << "8. Obroc w lewo wedlug wybranej wartosci" << endl;
	cout << "9. Obroc w prawo wedlug wybranej wartosci" << endl;
	cout << "10.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje: ";
}

uniform_int<int>::param_type changeRange(int number, uniform_int_distribution<> temp)
{
	{
		decltype(temp.param()) new_range(0, number);
		return new_range;
	}

}

void menu_array()
{
	bool valid;
	int randomPlace;
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	int val;
	int index;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 1000);
	Array array;
	uniform_int_distribution<> dist2(0, array.getSize()); // distribute results between 
	string path;
	int opt;
	do {
		displayMenu("--- TABLICA---");
		cin >> opt;

		cout << endl;
		switch (opt) {
		case 1:
			cout << "Podaj sciezke pliku: ";
			cin >> path;
			array.readFromFile(path);
			break;
		case 2:
			if (array.getSize() != 0)
			{
				array.deleteFromTheBeginning();
			}
			else cout << "tablica jest pusta" << endl;
			break;
		case 3: if (array.getSize() != 0)
		{
			array.deleteFromTheEnd();
		}
				else cout << "tablica jest pusta" << endl;
				break;
		case 4:
			if(array.getSize()!=0)
			{
				while (std::cout << "Wpisz index: " && (!(std::cin >> index))) {
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Wprowadzony z³y index, prosze wpisac ponownie.\n";
				}
				if ((index >= 0 && index < array.getSize()))
				{
					dist2.param(changeRange(array.getSize(), dist2));
					randomPlace = index;
					array.deleteFromRandomPlace(randomPlace);
				}
				else { cout << "nie mozna usunac" << endl; }
			}
			else { cout << "tablica jest pusta "; }
			

			break;
		case 5: while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}

			array.addAtTheBeginning(val);
			break;
		case 6: while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			array.addAtTheEnd(val);
			break;
		case 7:
			while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}
			while (std::cout << "Wpisz index: " && (!(std::cin >> index)) && (index >= 0 && index < array.getSize())) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzony z³y index, prosze wpisac ponownie.\n";
			}
			if((index >= 0 && index <= array.getSize()))
			{
				dist2.param(changeRange(array.getSize(), dist2));
				randomPlace = index;
				array.addToRandomPlace(val, randomPlace);
			}
			else { cout << "nie mozna dodac" << endl; }

			break;
		case 8:
			valid = false;
			while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}


			array.createRandomArray(val);
			cout << endl;
			break;
		case 9:valid = false;
			while (std::cout << "Jaka wartosc chcesz wyszukac? : " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}

			if (array.searchForValue(val) != -1)
			{
				cout << "Znaleziono wartosc " << endl;
			}
			else cout << "Nie znaleziono wartosci " << endl;
			cout << endl;
			break;

		case 10:array.showArray();
			break;

		case 11:


			ofstream myfile;
			myfile.open("pomiary_tablica.txt", std::ios_base::app);
			int element = array.getSize();
			myfile << "POMIARY DLA : " << element << " ELEMENTOW" << endl << endl << endl;

			myfile << "usuwanie na koncu: " << endl;
			if (array.getSize() != 0)
			{
				for (int i = 0; i<100; i++)
				{
					start = read_QPC();
					array.deleteFromTheEnd();
					elapsed = read_QPC() - start;



					cout << "Usuwanie na na koncu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				myfile << "usuwanie na poczatku: " << endl;

				for (int i = 0; i<100; i++)
				{
					start = read_QPC();
					array.deleteFromTheBeginning();
					elapsed = read_QPC() - start;

					cout << "Usuwanie na na poczatku " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}

				myfile << "usuwanie w losowym miejscu: " << endl;

				for (int i = 0; i<100; i++)
				{
					dist2.param(changeRange(array.getSize() - 1, dist2));
					randomPlace = dist2(gen);
					start = read_QPC();
					array.deleteFromRandomPlace(randomPlace);
					elapsed = read_QPC() - start;

					cout << "Usuwanie w losowym miejscu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}

			}
			else { cout << "Nie mo¿na dokonac pomiaru, lista pusta" << endl; }

			myfile << "dodawanie na poczatku : " << endl;

			for (int i = 0; i<100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;

				cout << "Dodowanie na pocz¹tku " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			myfile << "dodawanie na koncu : " << endl;

			for (int i = 0; i<100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;

				cout << "Dodowanie na koncu " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			myfile << "dodawanie w losowym miejscu : " << endl;


			if (array.getSize() != 0)
			{
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					dist2.param(changeRange(array.getSize() - 1, dist2));
					randomPlace = dist2(gen);
					start = read_QPC();
					array.addToRandomPlace(val, randomPlace);
					elapsed = read_QPC() - start;

					cout << "Dodowanie w losowym miejscu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}

			}
			array.createRandomArray(1000000);
			myfile << "wyszukiwanie liczby : " << endl;
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i<100; i++)
			{
			
				val = dist2(gen);
				cout << val << endl;
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;

				cout << "Wyszukiwanie liczby " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000000.0 * elapsed) / (frequency) << endl;

			}


			myfile << "usuwanie na koñcu: " << endl;

			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
			}
			myfile << endl << endl << endl;

			array.createRandomArray(40000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(70000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(160000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(190000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(220000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(250000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(280000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(300000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheEnd();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			myfile << "dodawanie na koñcu: " << endl;

			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
			}
			myfile << endl << endl << endl;

			array.createRandomArray(40000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(70000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(160000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(190000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(220000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(250000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(280000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(300000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			myfile << "dodawanie na pocz¹tku: " << endl;

			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
			}
			myfile << endl << endl << endl;

			array.createRandomArray(40000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(70000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;



			array.createRandomArray(160000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(190000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(220000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(250000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(280000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(300000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;



			myfile << "usuwanie na pocz¹tku: " << endl;

			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
			}
			myfile << endl << endl << endl;

			array.createRandomArray(40000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(70000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;



			array.createRandomArray(160000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(190000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(220000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(250000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(280000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(300000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			myfile << "usuwanie w losowym miejscu: " << endl;

			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				
				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(40000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(70000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(100000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;	for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;



			array.createRandomArray(160000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(190000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(220000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(250000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(280000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(300000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.deleteFromRandomPlace(randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;



			myfile << "dodawannie w losowym miejscu: " << endl;

			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(40000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(70000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(100000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(130000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;	for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;



			array.createRandomArray(160000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(190000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(220000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(250000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			array.createRandomArray(280000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;

			array.createRandomArray(300000);
			for (int i = 0; i < 100; i++)
			{

				val = dist2(gen);
				randomPlace = dist2(gen);
				start = read_QPC();
				array.addToRandomPlace(val, randomPlace);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				dist2.param(changeRange(array.getSize() - 1, dist2));
			}
			myfile << endl << endl << endl;


			myfile << "wyszukiwanie:  " << endl << endl;

			array.createRandomArray(10);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
			}
			myfile << endl << endl << endl;

			array.createRandomArray(100);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(1000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(10000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;



			array.createRandomArray(1000000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(10000000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			array.createRandomArray(100000000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			array.createRandomArray(100000000);
			dist2.param(changeRange(array.getSize() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				array.searchForValue(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;
			break;
		}




	} while (opt != 0);
}



void menu_list()
{	
	bool valid;
	int randomPlace;
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	int val;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 1000);
	DoublyLinkedList list;
	uniform_int_distribution<> dist2(0, list.getNumberOfElements()); // distribute results between 
	string path;
	int index;
	int opt;
	do {
		displayMenu("--- LISTA DWUKIERUNKOWA---");
		cin >> opt;

		cout << endl;
		switch (opt) {
		case 1: cout << "Podaj sciezke pliku: ";
			cin >> path;
			list.readFromFile(path);
			break;
		case 2:
			if(list.getNumberOfElements()!=0)
			{
				list.deleteFromTheBeginning();
			}
			else cout << "lista jest pusta" << endl;
			break;
		case 3: if (list.getNumberOfElements() != 0)
			{
			list.deleteFromTheEnd();
			}
			else cout << "lista jest pusta" << endl;
			break;
		case 4:
			if(list.getNumberOfElements()!=0)
			{
				while (std::cout << "Wpisz index: " && (!(std::cin >> index)) && (index >= 0 && index < list.getNumberOfElements())) {
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Wprowadzony z³y index, prosze wpisac ponownie.\n";
				}
				if ((index >= 0 && index < list.getNumberOfElements()))
				{
					dist2.param(changeRange(list.getNumberOfElements(), dist2));
					randomPlace = index;
					list.deleteFromRandomPlace(randomPlace);
				}
				else { cout << "nie mozna usunac" << endl; }
			}
			else { cout << "Nie mo¿na usunac elementu, lista jest pusta" << endl; }
			
			break;
		case 5: while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			list.addAtTheBeginning(val);
			break;
		case 6: while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			list.addAtTheEnd(val);
			break;
		case 7:
			
				while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
				}
				while (std::cout << "Wpisz index: " && (!(std::cin >> index))) {
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Wprowadzony z³y index, prosze wpisac ponownie.\n";
				}
				if ((index > 0 && index < list.getNumberOfElements()))
				{
					dist2.param(changeRange(list.getNumberOfElements(), dist2));
					list.addToRandomPlace(val,index);

				}
				else if(index==0)
				{
					list.addAtTheBeginning(val);
				}
				else if(index==list.getNumberOfElements())
				{
					list.addAtTheEnd(val);
				}
				else { cout << "nie mozna dodac" << endl; }
			
			
			break;
		case 8:
			valid = false;
			while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}
			

			list.createRandomList(val);
			cout << endl;
			break;
		case 9:valid = false;
			while (std::cout << "Jaka wartosc chcesz wyszukac? : " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}
			
			if(list.searchForValue(val)!= -1)
			{
				cout << "Znaleziono wartosc " << endl;
			}
			else cout << "Nie znaleziono wartosci " << endl;
			cout << endl;
			break;

		case 10:list.showList();
			break;

		case 11:
			
			
			ofstream myfile;
			myfile.open("pomiary_lista.txt", std::ios_base::app);
			int element = list.getNumberOfElements();
			myfile << "POMIARY DLA : " << element << " ELEMENTOW" << endl << endl << endl;

			myfile << "usuwanie na koncu: " << endl;
			if (list.getNumberOfElements() != 0)
			{
				cout << 10000 << endl << endl << endl;
				list.createRandomList(10000);
				for(int i =0; i<100;i++)
				{
					start = read_QPC();
					list.deleteFromTheEnd();
					elapsed = read_QPC() - start;



					cout << "Usuwanie na na koncu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 10000 << endl << endl << endl;
				list.createRandomList(100000);
				for (int i = 0; i<100; i++)
				{
					start = read_QPC();
					list.deleteFromTheEnd();
					elapsed = read_QPC() - start;



					cout << "Usuwanie na na koncu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 10000 << endl << endl << endl;
				list.createRandomList(10000);
				for (int i = 0; i<100; i++)
				{
					start = read_QPC();
					list.deleteFromTheEnd();
					elapsed = read_QPC() - start;



					cout << "Usuwanie na na koncu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}
					
			myfile << "usuwanie na poczatku: " << endl;

			for(int i=0;i<100;i++)
			{
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;

				cout << "Usuwanie na na poczatku " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			myfile << "usuwanie w losowym miejscu: " << endl;
				for(int i =0;i<100;i++)
				{
					dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
					randomPlace = dist2(gen);
					start = read_QPC();
					list.deleteFromRandomPlace(randomPlace);
					elapsed = read_QPC() - start;

					cout << "Usuwanie w losowym miejscu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
					
			}
			else { cout << "Nie mo¿na dokonac pomiaru, lista pusta" << endl; }
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			myfile << "dodawanie na poczatku : " << endl;

			for (int i = 0; i<100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;

				cout << "Dodowanie na pocz¹tku " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			myfile << "dodawanie na koncu : " << endl;
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for(int i=0;i<100;i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;

				cout << "Dodowanie na koncu " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			myfile << "dodawanie w losowym miejscu : " << endl;

				
			if(list.getNumberOfElements()!=0)
			{
				for(int i=0;i<100;i++)
				{
					dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
					val = dist2(gen);
					randomPlace = dist2(gen);
					start = read_QPC();
					list.addToRandomPlace(val, randomPlace);
					elapsed = read_QPC() - start;

					cout << "Dodowanie w losowym miejscu " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
					
			}
		
			myfile << "wyszukiwanie liczby : " << endl;
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for(int i =0;i<100;i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.searchForValue(val);
				elapsed = read_QPC() - start;

				cout << "Wyszukiwanie liczby " << endl;
				cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
					(frequency) << endl;
				cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					(frequency) << endl;
				cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
					(frequency) << endl << endl;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}


			double avarage = 0;
			myfile << "dodawanie na koñcu: " << endl;

			list.createRandomList(10000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				avarage = avarage + ((1000000.0 * elapsed) / (frequency));
			}
			myfile << endl << endl << endl;
		
			list.createRandomList(40000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			list.createRandomList(70000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(100000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(130000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(130000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(160000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(190000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(220000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(250000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(280000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			list.createRandomList(300000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheEnd(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			myfile << "dodawanie na pocz¹tku: " << endl;

			list.createRandomList(10000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				avarage = avarage + ((1000000.0 * elapsed) / (frequency));
			}
			myfile << endl << endl << endl;

			list.createRandomList(40000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			list.createRandomList(70000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(100000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(130000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(130000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(160000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(190000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(220000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(250000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(280000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			list.createRandomList(300000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.addAtTheBeginning(val);
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;



			myfile << "usuwanie na pocz¹tku: " << endl;

			list.createRandomList(10000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				avarage = avarage + ((1000000.0 * elapsed) / (frequency));
			}
			myfile << endl << endl << endl;

			list.createRandomList(40000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			list.createRandomList(70000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(100000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(130000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;



			list.createRandomList(160000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(190000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(220000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(250000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			list.createRandomList(280000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;

			list.createRandomList(300000);
			dist2.param(changeRange(list.getNumberOfElements() - 1, dist2));
			for (int i = 0; i < 100; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				list.deleteFromTheBeginning();
				elapsed = read_QPC() - start;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			myfile << endl << endl << endl;


			
			break;
		}

		
		

	} while (opt != 0);
}

void menu_heap()
{
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	int opt;
	int val;
	random_device rd;
	mt19937 gen(rd());
	Heap heap;
	uniform_int_distribution<> dist2(0, heap.getSize()); // distribute results between 
	string path;
	heap.cr = heap.cl = heap.cp = "  ";
	heap.cr[0] = 218; heap.cr[1] = 196;
	heap.cl[0] = 192; heap.cl[1] = 196;
	heap.cp[0] = 179;
	do {
		displayHeap("--- KOPIEC---");
		cin >> opt;
		cout << endl;
		switch (opt) {
		case 1: cout << "Podaj sciezke pliku: ";
			cin >> path;
			heap.readFromFile(path);
			break;
		case 2:
			try
			{
				heap.deleteFromTheBotton();

			}
			catch(string exception){
				cout << exception << endl;
			}
			break;
		case 3:while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			heap.addValue(val);
			cout << endl;
			break;
		case 4: while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			heap.createRandomHeap(val);
			cout << endl;
			break;
		case 5: while (std::cout << "Wpisz liczbe: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}

				if (heap.searchForValue(val) != -1)
				{
					cout << "Znaleziono wartosc " << endl;
				}
				else cout << "Nie znaleziono wartosci " << endl;
				cout << endl;
			break;
		case 6: heap.printHeap("","",0);
			break;
		case 7:
			ofstream myfile;
			myfile.open("pomiary_kopiec.txt", std::ios_base::app);
			int element = heap.getSize();
			/*myfile << "POMIARY DLA : " << element << " ELEMENTOW" << endl << endl << endl;

			myfile << "usuwanie korzenia: " << endl;
			if (heap.getSize() != 0)
			{
				cout << 10000 << endl << endl << endl << endl;
				heap.createRandomHeap(10000);
				myfile << "POMIARY DLA : " << 10000 << " ELEMENTOW" << endl << endl << endl;
				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 100000 << endl << endl << endl << endl;
				heap.createRandomHeap(40000);
				myfile << "POMIARY DLA : " << 40000 << " ELEMENTOW" << endl << endl << endl;
				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 200000 << endl << endl << endl << endl;
				heap.createRandomHeap(70000);
				myfile << "POMIARY DLA : " << 70000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 100000 << endl << endl << endl << endl;
				heap.createRandomHeap(100000);
				myfile << "POMIARY DLA : " << 100000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 130000 << endl << endl << endl << endl;
				heap.createRandomHeap(130000);
				myfile << "POMIARY DLA : " << 130000 << " ELEMENTOW" << endl << endl << endl;
				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 160000 << endl << endl << endl << endl;
				heap.createRandomHeap(160000);
				myfile << "POMIARY DLA : " << 160000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 190000 << endl << endl << endl << endl;
				heap.createRandomHeap(190000);
				myfile << "POMIARY DLA : " << 190000 << " ELEMENTOW" << endl << endl << endl;
				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 210000 << endl << endl << endl << endl;
				heap.createRandomHeap(210000);
				myfile << "POMIARY DLA : " << 210000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 240000 << endl << endl << endl << endl;
				heap.createRandomHeap(240000);
				myfile << "POMIARY DLA : " << 240000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 270000 << endl << endl << endl << endl;
				heap.createRandomHeap(270000);
				myfile << "POMIARY DLA : " << 270000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 300000 << endl << endl << endl << endl;
				heap.createRandomHeap(300000);
				myfile << "POMIARY DLA : " << 300000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}

				cout << 330000 << endl << endl << endl << endl;
				heap.createRandomHeap(330000);
				myfile << "POMIARY DLA : " << 330000 << " ELEMENTOW" << endl << endl << endl;

				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}
				cout << 360000 << endl << endl << endl << endl;
				heap.createRandomHeap(360000);
				myfile << "POMIARY DLA : " << 360000 << " ELEMENTOW" << endl << endl << endl;
				for (int i = 0; i < 100; i++)
				{
					start = read_QPC();
					heap.deleteFromTheBotton();
					elapsed = read_QPC() - start;



					cout << "Usuwanie korzenia " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
				}



			}
			else { cout << "Nie mo¿na dokonac pomiaru, lista pusta" << endl; }

				cout << 10000 << endl << endl << endl << endl;
				heap.createRandomHeap(10000);
				myfile << "POMIARY DLA : " << 10000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}

				cout << 40000 << endl << endl << endl << endl;
				heap.createRandomHeap(40000);
				myfile << "POMIARY DLA : " << 40000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 70000 << endl << endl << endl << endl;
				heap.createRandomHeap(70000);
				myfile << "POMIARY DLA : " << 70000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 100000 << endl << endl << endl << endl;
				heap.createRandomHeap(100000);
				myfile << "POMIARY DLA : " << 100000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 130000 << endl << endl << endl << endl;
				heap.createRandomHeap(130000);
				myfile << "POMIARY DLA : " << 130000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 160000 << endl << endl << endl << endl;
				heap.createRandomHeap(160000);
				myfile << "POMIARY DLA : " << 160000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 190000 << endl << endl << endl << endl;
				heap.createRandomHeap(190000);
				myfile << "POMIARY DLA : " << 190000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 210000 << endl << endl << endl << endl;
				heap.createRandomHeap(210000);
				myfile << "POMIARY DLA : " << 210000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 240000 << endl << endl << endl << endl;
				heap.createRandomHeap(240000);
				myfile << "POMIARY DLA : " << 240000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 270000 << endl << endl << endl << endl;
				heap.createRandomHeap(270000);
				myfile << "POMIARY DLA : " << 270000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 300000 << endl << endl << endl << endl;
				heap.createRandomHeap(300000);
				myfile << "POMIARY DLA : " << 300000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 330000 << endl << endl << endl << endl;
				heap.createRandomHeap(330000);
				myfile << "POMIARY DLA : " << 330000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}
				cout << 360000 << endl << endl << endl << endl;
				heap.createRandomHeap(360000);
				myfile << "POMIARY DLA : " << 360000 << " ELEMENTOW" << endl << endl << endl;
				myfile << "dodawanie wartosci: " << endl;
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i<100; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.addValue(val);
					elapsed = read_QPC() - start;

					cout << "Dodawanie liczby " << endl;
					cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
						(frequency) << endl;
					cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						(frequency) << endl;
					cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
						(frequency) << endl << endl;
					myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

				}*/
				double avarage = 0;
				myfile << "wyszukiwanie liczby : " << endl;
		
				heap.createRandomHeap(10);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;

				avarage = 0;
				heap.createRandomHeap(100);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
				avarage = 0;

				heap.createRandomHeap(1000);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
				avarage = 0;

				heap.createRandomHeap(10000);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
				avarage = 0;

				heap.createRandomHeap(100000);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
				avarage = 0;
				heap.createRandomHeap(1000000);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
				avarage = 0;
				heap.createRandomHeap(10000000);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
				avarage = 0;

				heap.createRandomHeap(100000000);
				dist2.param(changeRange(heap.getSize() - 1, dist2));
				for (int i = 0; i < 200; i++)
				{
					val = dist2(gen);
					start = read_QPC();
					heap.searchForValue(val);
					elapsed = read_QPC() - start;
					avarage += (1000000.0 * elapsed) /
						frequency;

				}
				myfile << avarage / 200 << endl;
			break;

		
		
		}

	} while (opt != 0);
}

void menu_BSTree()
{
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	int val;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-1000, 1000);
	BinarySearchTree tree;
	uniform_int_distribution<> dist2(0,tree.getSize() ); // distribute results between 
	string path;

	tree.cr = tree.cl = tree.cp = "  ";
	tree.cr[0] = 218; tree.cr[1] = 196;
	tree.cl[0] = 192; tree.cl[1] = 196;
	tree.cp[0] = 179;
	int opt;
	do {
		displayBST("--- DRZEWO BST---");
		cin >> opt;
		cout << endl;
		switch (opt) {
		case 1:
			cout << "Podaj sciezke pliku: ";
			cin >> path; 
			tree.readFromFile(path);
			break;
		case 2:while (std::cout << "Wpisz jak liczbe chcesz usunac: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			if(tree.deleteValue(val)!=nullptr)
			{
				cout << "wartosc usunieto" << endl;
			}
			else cout << "wartosc nie istnieje"  << endl;
			cout << endl;
			break;
		case 3:while (std::cout << "Wpisz jaka liczbe chcesz dodac? : " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			tree.addValue(val);
			cout << endl;
			break;
		case 4: while (std::cout << "Podaj liczbe wartosci: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			tree.createRandomTree(val);
			cout << endl;
			break;
		case 5: while (std::cout << "Jakie numer chcesz znalezc?: " && !(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
		}
			if(tree.searchForValue(tree.getRoot(), val)!=nullptr)
			{
				cout << "wartosc znaleziono" << endl;
			}
			else cout << "nie znaleziono wartosci" << endl;
			cout << endl;
			break;
		case 6: tree.printBT("", "", tree.root);
			break;
		case 7:tree.rebalanceDSW();
			break;
		case 8:
			while (std::cout << "Podaj liczbe wartosci: " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}
			if (tree.doTurnLeft(val) == nullptr) { cout << "nie istnieje taka wartosc" << endl; };
			break;

		
		case 9:
			while (std::cout << "Podaj liczbe wartosci: " && !(std::cin >> val)) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Wprowadzona zla wartosc, prosze wpisac ponownie.\n";
			}
			if (tree.doTurnRight(val) == nullptr) { cout << "nie istnieje taka wartosc" << endl; };
			break;
		
		case 10:
			double avarage = 0;
			tree.rebalanceDSW();
			ofstream myfile;
			myfile.open("pomiary_drzewo.txt", std::ios_base::app);
			/*myfile << "usuwanie eleemntu : " << endl;
			tree.createRandomTree(10000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;
			
			tree.rebalanceDSW();
			cout << endl << endl;

			tree.createRandomTree(40000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			cout << endl << endl;


			tree.rebalanceDSW();

			tree.createRandomTree(70000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;


			}
			myfile << avarage / 200 << endl;
			avarage = 0;

			tree.rebalanceDSW();
			

			tree.createRandomTree(100000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;

			}
			avarage = 0;

			tree.rebalanceDSW();
			cout << endl << endl;

			tree.createRandomTree(130000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;

			}
			myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;
			avarage = 0;
			cout << endl << endl;

			tree.rebalanceDSW();

			tree.createRandomTree(160000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			cout << endl << endl;


			tree.rebalanceDSW();

			tree.createRandomTree(190000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			tree.rebalanceDSW();

			tree.createRandomTree(210000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			
			cout << endl << endl;

			tree.rebalanceDSW();

			tree.createRandomTree(240000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;
			cout << endl << endl;
			tree.rebalanceDSW();
			tree.createRandomTree(270000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;
			myfile << endl << endl;;
			tree.rebalanceDSW();

			tree.createRandomTree(300000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			

			tree.rebalanceDSW();

			tree.createRandomTree(330000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			

			tree.rebalanceDSW();

			tree.createRandomTree(360000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.deleteValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;


			}
			

			tree.rebalanceDSW();

			cout << endl << endl;
			myfile << "dodawanie elementu : " << endl;
			tree.createRandomTree(10000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(40000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(70000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;


			}
			avarage = 0;

			tree.rebalanceDSW();


			tree.createRandomTree(100000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(130000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;

			}
			myfile << avarage / 200 << endl;
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(160000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;


			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(190000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(210000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(240000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;


			}
			avarage = 0;

			tree.rebalanceDSW();
			tree.createRandomTree(270000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(300000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(330000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();

			tree.createRandomTree(360000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.addValue(val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();*/


			cout << endl << endl;
			myfile << "szukanie elementu : " << endl;
			tree.createRandomTree(1);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root,val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}

			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(40000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(70000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;

				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;


			tree.createRandomTree(100000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(130000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(160000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(190000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(210000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(240000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;
			myfile << endl << endl;

			tree.rebalanceDSW();
			tree.createRandomTree(270000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(300000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(330000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			tree.rebalanceDSW();
			myfile << endl << endl;

			tree.createRandomTree(36000000);
			tree.rebalanceDSW();
			dist2.param(changeRange(tree.getSize() - 1, dist2));
			for (int i = 0; i < 200; i++)
			{
				val = dist2(gen);
				start = read_QPC();
				tree.searchForValue(tree.root, val);
				elapsed = read_QPC() - start;
				avarage += (1000000.0 * elapsed) /
					frequency;
				myfile << setprecision(0) << (1000000.0 * elapsed) / (frequency) << endl;

			}
			avarage = 0;

			


			break;


		}

	} while (opt != 0);
}

int main(int argc, char* argv[])
{


	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.Drzewo BST" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje: ";
		option =_getche();
		cout << endl;

		switch (option) {
		case '1':
			menu_array();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
		case '4':
			menu_BSTree();
			break;
		}
		


	} while (option != '0');

	


	return 0;
}