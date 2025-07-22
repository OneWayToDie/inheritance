#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERES const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERES last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERES)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//					Methods:
	void info()const
	{
		cout << "Фамилия - " << last_name << ", " << "Имя - " << first_name << ", " << "Возраст - " << age << "  ";
	}
};

#define STUDENT_TAKE_PARAMETERES  const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERES  speciality, group, rating, attendance

class Student:public Human
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
	Student(HUMAN_TAKE_PARAMETERES,STUDENT_TAKE_PARAMETERES):Human(HUMAN_GIVE_PARAMETERES)
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

#define TEACHER_TAKE_PARAMETERES const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERES speciality, experience

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	//				Constructors:
	Teacher(HUMAN_TAKE_PARAMETERES, TEACHER_TAKE_PARAMETERES) :Human(HUMAN_GIVE_PARAMETERES)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << "Специальность - " << speciality << ", " << "опыт работы - " << experience << endl;
	}
};


#define GRADUATE_TAKE_PARAMETERES const std::string& theme_of_work, const std::string& date_of_diploma_defense, int scores_of_practice, int scores_of_theory, int average_score
#define GRADUATE_GIVE_PARAMETEES theme_of_work, date_of_diploma_defense, scores_of_practice, scores_of_theory, average_score

class Graduate :public Human
{
	std::string theme_of_work;
	std::string date_of_diploma_defense;
	int scores_of_practice;
	int scores_of_theory;
	int average_score;
public:
	const std::string& get_theme_of_work()const
	{
		return theme_of_work;
	}
	const std::string& get_date_of_diploma_defense()const
	{
		return date_of_diploma_defense;
	}
	int get_scores_of_practice()const
	{
		return scores_of_practice;
	}
	int get_scores_of_theory()const
	{
		return scores_of_theory;
	}
	int get_average_score()const
	{
		return average_score;
	}
	void set_theme_of_work(const std::string& theme_of_work)
	{
		this->theme_of_work = theme_of_work;
	}
	void set_date_of_diploma_defense(const std::string& date_of_diploma_defense)
	{
		this->date_of_diploma_defense = date_of_diploma_defense;
	}
	void set_scores_of_practice(int scores_of_practice)
	{
		this->scores_of_practice = scores_of_practice;
	}
	void set_scores_of_theory(int scores_of_theory)
	{
		this->scores_of_theory = scores_of_theory;
	}
	void set_average_score(int average_score)
	{
		this->average_score = (scores_of_theory+scores_of_practice)/2;
	}

	//					constructors:
	Graduate(HUMAN_TAKE_PARAMETERES, GRADUATE_TAKE_PARAMETERES) :Human(HUMAN_GIVE_PARAMETERES)
	{
		set_theme_of_work(theme_of_work);
		set_date_of_diploma_defense(date_of_diploma_defense);
		set_scores_of_practice(scores_of_practice);
		set_scores_of_theory(scores_of_theory);
		set_average_score(average_score);
		cout << "GConstructors:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//				Methods:
	void info()const
	{
		Human::info();
		cout << "Тема дипломной работы - " << theme_of_work << ", " << "Дата защиты диплома - " << date_of_diploma_defense << ", " << "Баллы за практику - "<< scores_of_practice << ", " << "Баллы за теорию - " << scores_of_theory << ", " << "Средний балл - " << average_score << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Danila", "Debilovi4", 25, "nifiga nedelanie", "20.09.2025", 80, 0, 0);
	graduate.info();
}