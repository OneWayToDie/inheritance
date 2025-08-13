#include"stdafx.h"
#include"Data.h"


void main()
{
	setlocale(LC_ALL, "");

	Data* data_group[] =
	{
		new Data(1999, 11, 15),
		new Data(1980, 110, 15),
		new Data(2005, 14, 123),
		new Data(1570, 4, 36)
	};
	Data data0(1975, 11, 44);
	Data data1(1976, 10, 12);
	Data data2(1976, 273, 124);
	data0.prinimaemaya_data(cout);
	data1.prinimaemaya_data(cout);
	data2.prinimaemaya_data(cout);
	Data data3(2, 8, 10);
	Data data4 = data0 + data3;
	data4.prinimaemaya_data(cout);
	Data data5(1024, 17, 11);
	data5.prinimaemaya_data(cout);
	Data data6 = data1 - data5;
	data6.prinimaemaya_data(cout);


	std::ofstream fout("Data.txt");
	fout << data0 << endl;
	fout << data1 << endl;
	fout << data2 << endl;
	fout << data3 << endl;
	fout << data4 << endl;
	fout << data5 << endl;
	fout << data6 << endl;
	for (int i = 0; i < sizeof(data_group) / sizeof(data_group[0]); i++)
	{
		data_group[i]->prinimaemaya_data(cout);
		fout << *data_group[i] << endl;
	}
	fout.close();
	system("notepad Data.txt");

	for (int i = 0; i < sizeof(data_group) / sizeof(data_group[0]); i++)
	{
		delete data_group[i];
	}
}