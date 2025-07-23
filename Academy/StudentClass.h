#pragma once
#include"BaseClass.h"

#define STUDENT_TAKE_PARAMETERES  const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERES  speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;		//успеваемость
	double attendance;	//посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERES, STUDENT_TAKE_PARAMETERES) :Human(HUMAN_GIVE_PARAMETERES)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	void info()const
	{
		Human::info();
		cout << "Специальность - " << speciality << ", " << "Номер группы - " << group << ", " << "Рейтинг - " << rating << ", " << "Успеваемость - " << attendance << endl;
	}
};