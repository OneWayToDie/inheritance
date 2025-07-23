#pragma once
#include"BaseClass.h"

#define ELDER_TAKE_PARAMETERES bool Responsibility, bool Justice, bool Communication_skills, bool Organizational_skills
#define ELDER_GIVE_PARAMETERES  Responsibility, Justice, Communication_skills, Organizational_skills

class Elder :public Human, Student
{
	bool Responsibility;//Ответственность
	bool Justice;	//Справедливость
	bool Communication_skills;	//коммуникабельность
	bool Organizational_skills;	//Организаторские навыки
public:
	bool get_Responsibility()const
	{
		return Responsibility;
	}
	bool get_Justice()const
	{
		return Justice;
	}
	bool get_Communication_skills()const
	{
		return Communication_skills;
	}
	bool get_Organizational_skills()const
	{
		return Organizational_skills;
	}
	void set_Responsibility(bool Responsibility)
	{
		this->Responsibility = Responsibility;
	}
	void set_Justice(bool Justice)
	{
		this->Justice = Justice;
	}
	void set_Communication_skills(bool Communication_skills)
	{
		this->Communication_skills = Communication_skills;
	}
	void set_Organizational_skills(bool Organizational_skills)
	{
		this->Organizational_skills = Organizational_skills;
	}
	//				Constructors:
	Elder(HUMAN_TAKE_PARAMETERES,STUDENT_TAKE_PARAMETERES, ELDER_TAKE_PARAMETERES) :Human(HUMAN_GIVE_PARAMETERES), Student(HUMAN_GIVE_PARAMETERES, STUDENT_GIVE_PARAMETERES)
	{
		set_Responsibility(Responsibility);
		set_Justice(Justice);
		set_Communication_skills(Communication_skills);
		set_Organizational_skills(Organizational_skills);
		cout << "EConstructor:\t" << this << endl;
	}
	~Elder()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	//				Methods:
	void info()const
	{
		Student::info();
		cout << "Ответственность - " << Responsibility << ", " << "Справедливость - " << Justice << ", " << "Коммуникабельность - " << Communication_skills << ", " << "Организаторские навыки - " << Organizational_skills << endl;
	}
};
