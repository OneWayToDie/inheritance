#pragma once
#include"Human.h"


#define WORKERS_TAKE_PARAMETERS const std::string& job_title, const std::string& work_shift, const std::string& work_schedule, int work_experience, int Salary
#define WORKERS_GIVE_PARAMETERS job_title, work_shift, work_schedule, work_experience, Salary

class Workers :public Human
{
	std::string job_title;		//Должность
	std::string work_shift;		//Рабочая смена
	std::string work_schedule;	//График работы
	int work_experience;		//Стаж работы
	int Salary;					//Зарплата
public:
	const std::string& get_job_title()const
	{
		return job_title;
	}
	const std::string& get_work_shift()const
	{
		return work_shift;
	}
	const std::string& get_work_schedule()const
	{
		return work_schedule;
	}
	int get_work_experience()const
	{
		return work_experience;
	}
	int get_salary()const
	{
		return Salary;
	}
	void set_job_title(const std::string& job_title)
	{
		this->job_title = job_title;
	}
	void set_work_shift(const std::string& work_shift)
	{
		this->work_shift = work_shift;
	}
	void set_work_schedule(const std::string& work_schedule)
	{
		this->work_schedule = work_schedule;
	}
	void set_work_experience(int work_experience)
	{
		this->work_experience = work_experience;
	}
	void set_Salary(int Salary)
	{
		this->Salary = Salary;
	}
	//			Constructors:
	Workers(HUMAN_TAKE_PARAMETERS, WORKERS_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_job_title(job_title);
		set_work_shift(work_shift);
		set_work_schedule(work_schedule);
		set_work_experience(work_experience);
		set_Salary(Salary);
		cout << "WConstructors:\t" << this << endl;
	}
	~Workers()
	{
		cout << "WDestructor:\t" << this << endl;
	}
	//			Methods:
	std::ostream& info(std::ostream& os)const override
	{
		return Human::info(os) << "Должность - " << job_title << ", " << "Рабочая смена - " << work_shift << ", " << "График работы - " << work_schedule << ", " << "Стаж работы - " << work_experience << ", " << "Зарплата - " << Salary << endl;
	}
};
