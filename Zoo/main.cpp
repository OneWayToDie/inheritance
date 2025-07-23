#include"stdafx.h"
#include"Human.h"
#include"Workers.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	Human* group_Human[] =
	{
		new Human("Asphodel", "Vladimirov", 22, 74.6),
		new	Human("Adam", "Janson", 37, 86.4),
		new Human("Danila", "Nikiforov", 25, 66.2),
		new Human("Bruce", "Wayne", 40, 90),
		new Human("No_name", "Undefined", 24, 125)
	};

	cout << delimiter << endl;

	cout << "Просто люди с улицы: " << "\n\n";

	for (int i = 0; i < sizeof(group_Human) / sizeof(group_Human[0]); i++)
	{
		group_Human[i]->info();											//Вывод инфы о людях
	}


	cout << delimiter << endl;


	Workers* group_Workers[] =
	{
		new Workers("Artem", "Vorobiev", 26, 74.6, "Смотритель", "дневная", "2/2", 6, 50000),
		new Workers("Anton", "Zaicev", 32, 63.1, "уборщик", "дневная", "5/2", 1, 25000),
		new Workers("Liza", "Valerieva", 21, 52.1, "Волонтёр", "дневная", "свободный график", 2, 15000),
		new Workers("Grigoriy", "Pavlov", 45, 78.1, "Главный смотритель", "дневная", "6/1", 15, 90000),
	};



	cout << "\n" << "Работники зоопарка:  " << "\n\n\n";
	for (int i = 0; i < sizeof(group_Workers) / sizeof(group_Workers[0]); i++)
	{
		group_Workers[i]->info();										//Вывод инфы о рабочих
		cout << delimiter << endl;
	}








	for (int i = 0; i < sizeof(group_Workers) / sizeof(group_Workers[0]); i++)
	{
		delete group_Workers[i];										//Делимитер рабочих
	}

	cout << delimiter << endl;

	for (int i = 0; i < sizeof(group_Human) / sizeof(group_Human[0]);i++)
	{
		delete group_Human[i];											//Делимитер людей
	}
}