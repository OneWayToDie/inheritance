#include"stdafx.h"
#include"Human.h"
#include"Workers.h"
#include"Zoo.h"
#include"Animals.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	cout << delimiter << endl;

	cout << "Информация о Зоопарке: " << "\n\n";

	Zoo zoo("В будни с 7 утра до 22:00, в выходные с 8:30 до 23:00, время кормёжки с рук - 13:00-14:00", 34, 41, 18);
	zoo.info();

	cout << delimiter << endl;

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
		new Workers("Artem", "Vorobiev", 26, 74.6, "Смотритель зоопарка", "дневная", "2/2", 6, 50000),
		new Workers("Anton", "Zaicev", 32, 63.1, "уборщик", "дневная", "5/2", 1, 25000),
		new Workers("Liza", "Valerieva", 21, 52.1, "Зоолог", "дневная", "свободный график", 2, 45000),
		new Workers("Grigoriy", "Pavlov", 45, 78.1, "Ветеринар", "дневная", "6/1", 15, 90000)
	};



	cout << "\n" << "Работники зоопарка:  " << "\n\n\n";
	for (int i = 0; i < sizeof(group_Workers) / sizeof(group_Workers[0]); i++)
	{
		group_Workers[i]->info();										//Вывод инфы о рабочих
		cout << delimiter << endl;
	}


	Animals* group_Animals[] =
	{
		new Animals("Хордовые", "Пресмыкающиеся", "Крокодилы", "Настоящие крокодилы", "Крокодилы", "Гребнистый крокодил", "Северное побережье Австралии и острова Индонезии", 2),
		new Animals("Хордовые", "Млекопитающие", "Непарнокопытные", "Лошадиные", "Лошади", "Бурчеллова зебра", "Юго-восточная Африка, Южная Эфиопия", 3),
		new Animals("Хордовые", "Млекопитающие", "Хоботные", "Слоновые", "Слон", "Слон африканский", "Саванны и тропические леса", 4),
		new Animals("Хордовые", "Млекопитающие", "Грызуны", "Беличьи", "Летяги азиатские", "Летяга обыкновенная", "Северовосточная Германия, Тундра, Кольский полуостров", 7),
		new Animals("Хордовые", "Млекопитающие", "Хищные", "Куньи", "Ласки и хорьки", "Степной хорёк", "Средняя и центральная Азия", 4)
	};

	cout << "\n\nИнформация о животных содержащихся в зоопраке:\n\n\n";
	for (int i = 0; i < sizeof(group_Animals) / sizeof(group_Animals[0]); i++)
	{
		group_Animals[i]->info();				// Вывод информации о животных
		cout << delimiter << endl;
	}


	for (int i = 0; i < sizeof(group_Animals) / sizeof(group_Animals[0]); i++)
	{
		delete group_Animals[i];										//Делимитер животных
	}
	cout << delimiter << endl;
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