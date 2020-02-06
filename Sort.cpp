#include <iostream>
#include <ctime>
#include "Timer.h"
using namespace std;
using AorD=bool (*)(int, int);
const int n = 10;


bool ascending(int a,int b)
{
	return a >= b;
}
bool descending(int a, int b)
{
	return a <= b;
}

void show(int* m)
{
	for (int i = 0; i < n; i++)
		cout << m[i]<<" ";
	cout << endl;
}

void sortV(int* m, AorD currentSort)
{
	cout << "Сортировка выбором:\n";
	int q = 0, k, count = 0;
	for (int j = 0; j < n; j++)
	{
		k = j;
		for (int i = j; i < n; i++)
		{
			if (currentSort(m[k],m[i]))
				k = i;
			count++;
		}
		q = m[k];
		m[k] = m[j];
		m[j] = q;
	}
	cout << "Количество итераций: " << count << endl;
}

void sortP(int* m,AorD CurrentSort)
{
	cout << "Сортировка пузырьком:\n";
	int q = 0, count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n-i; j++)
		{
			if (CurrentSort(m[j-1],m[j]))
			{
				q = m[j-1];
				m[j-1] = m[j];
				m[j] = q;
			}
			count++;
		}
		
	}
	cout << "Количество итераций: " << count << endl;
}

int main()
{
	srand(time(0));
	system("chcp 1251>nul");
	int* m;
	m = new int[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = rand() % 100;
	}
	cout << "№1. Not Sort:\n";
	show(m);
	Timer t;
	sortV(m,ascending);
	cout << "Time taken: " << t.elapsed() << endl;
	t.reset();
	cout << "Sort:\n";
	show(m);
	cout << "*****************************************************************" << endl;
	for (int i = 0; i < n; i++)
		m[i] = rand() % 100;
	cout << "№2. Not Sort:\n";
	show(m);
	sortP(m,ascending);
	cout << "Time taken: " << t.elapsed() << endl;
	t.reset();
	cout << "Sort:\n";
	show(m);
	system("pause>nul");
	return 0;
}
