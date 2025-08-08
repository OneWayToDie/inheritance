#pragma once
#include"stdafx.h"

#define ZOO_TAKE_PARAMETERS const std::string& working_hours, int number_of_employees, int number_of_animal_enclosures, int number_of_animal_species
#define ZOO_GIVE_PARAMETERS working_hours, number_of_employees, number_of_animal_enclosures, number_of_animal_species

class Zoo
{
	std::string working_hours;			//Время работы зоопарка
	int number_of_employees;			//Количество работников зоопарка
	int number_of_animal_enclosures;	//Количество вольеров для животных
	int number_of_animal_species;		//Количество видов животных
public:
	const std::string& get_working_hours()const
	{
		return working_hours;
	}
	int get_number_of_employees()const
	{
		return number_of_employees;
	}
	int get_number_of_animal_enclosures()const
	{
		return number_of_animal_enclosures;
	}
	int get_number_of_animal_species()const
	{
		return number_of_animal_species;
	}
	void set_working_hours(const std::string& working_hours)
	{
		this->working_hours = working_hours;
	}
	void set_number_of_employees(int number_of_employees)
	{
		this->number_of_employees = number_of_employees;
	}
	void set_number_of_animal_enclosures(int number_of_animal_enclosures)
	{
		this->number_of_animal_enclosures = number_of_animal_enclosures;
	}
	void set_number_of_animal_species(int number_of_animal_species)
	{
		this->number_of_animal_species = number_of_animal_species;
	}
	//			constructors:
	Zoo(ZOO_TAKE_PARAMETERS)
	{
		set_working_hours(working_hours);
		set_number_of_employees(number_of_employees);
		set_number_of_animal_enclosures(number_of_animal_enclosures);
		set_number_of_animal_species(number_of_animal_species);
	/*	cout << "ZConstructor:\t" << this << endl;*/
	}
	~Zoo()
	{
		cout << "ZDestructor:\t" << this << endl;
	}
	//			Methods:
	std::ostream& info(std::ostream& os)const
	{
		return os << "Время работы зоопарка - " << working_hours << "\n" << "Количество занятых рабочих мест - " << number_of_employees << "\n" << "Количество вольеров с животными - " << number_of_animal_enclosures << "\n" << "Количество видов животных - " << number_of_animal_species << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Zoo& obj)
{
	return obj.info(os);
}