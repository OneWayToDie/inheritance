#pragma once
#include"stdafx.h"

#define HUMAN_TAKE_PARAMETERS const std::string& first_name, const std::string& last_name, int Age, double Weight
#define HUMAN_GIVE_PARAMETERS first_name, last_name, Age, Weight

class Human
{
	std::string first_name;		//Имя
	std::string last_name;		//Фамилия
	int Age;					//Возраст
	double Weight;				//Вес
public:
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const std::string& get_last_name()const
	{
		return last_name;
	}
	int get_Age()const
	{
		return Age;
	}
	double get_Weight()const
	{
		return Weight;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_Age(int Age)
	{
		this->Age = Age;
	}
	void set_Weight(double Weight)
	{
		this->Weight = Weight;
	}
	//				Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_first_name(first_name);
		set_last_name(last_name);
		set_Age(Age);
		set_Weight(Weight);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//				Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << "Имя - " << first_name << ", " << "Фамилия - " << last_name << ", " << "Возраст - " << Age << ", " << "Вес(в кг) - " << Weight << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}