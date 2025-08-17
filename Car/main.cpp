#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

#define CAR_TAKE_PARAMETERS	const std::string& Brand, const std::string& Model, int year_of_issue

class Car
{
	std::string Brand;
	std::string Model;
	int year_of_issue;
public:
	const std::string& get_Brand()const
	{
		return Brand;
	}
	const std::string& get_Model()const
	{
		return Model;
	}
	int get_year_of_issue()const
	{
		return year_of_issue;
	}
	void set_Brand(const std::string& Brand)
	{
		this->Brand = Brand;
	}
	void set_Model(const std::string& Model)
	{
		this->Model = Model;
	}
	void set_year_of_issue(int year_of_issue)
	{
		this->year_of_issue = year_of_issue;
	}
	//			Constructors:
	Car(CAR_TAKE_PARAMETERS)
	{
		set_Brand(Brand);
		set_Model(Model);
		set_year_of_issue(year_of_issue);
		cout << "CConstructors:\t\t" << endl;
	}
	virtual ~Car()
	{
		cout << "CDestructor:\t\t" << endl;
	}
	//			Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << "Брэнд и модель автомобиля - " << Brand << " " << Model << ", " << "Год выпуска - " << year_of_issue << endl;
	}
};

std::ostream& operator << (std::ostream& os, const Car& obj)
{
	return obj.info(os);
}

void main()
{
	setlocale(LC_ALL, "");

	Car* car_group[] =
	{
		new Car("Nissan", "Qashqai", 2006),
		new Car("Chevrolet", "Aveo", 2002),
		new Car("Suzuki", "Grand Vitara", 1997)
	};

	cout << "Part 1:\n" << endl;
	for (int i = 0; i < sizeof(car_group) / sizeof(car_group[0]); i++)
	{
		car_group[i]->info(cout);
	}
	cout << "\n";
	for (int i = 0; i < sizeof(car_group) / sizeof(car_group[0]); i++)
	{
		delete car_group[i];
	}
}