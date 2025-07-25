#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"

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
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//					Methods:
	virtual std::ostream& info(std::ostream& os)const	// BaseClass
	{
		return os << "Фамилия - " << last_name << ", " << "Имя - " << first_name << ", " << "Возраст - " << age << "  ";
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}

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
	std::ostream& info(std::ostream& os)const override	//Derived class
	{
		return Human::info(os) << "Специальность - " << speciality << ", " << "Номер группы - " << group << ", " << "Рейтинг - " << rating << ", " << "Успеваемость - " << attendance;
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
	std::ostream& info(std::ostream& os)const override
	{
		return Human::info(os) << "Специальность - " << speciality << ", " << "опыт работы - " << experience;
	}
};


#define GRADUATE_TAKE_PARAMETERES const std::string& subject
#define GRADUATE_GIVE_PARAMETERES subject

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//			Constructors:
	Graduate(HUMAN_TAKE_PARAMETERES, STUDENT_TAKE_PARAMETERES, GRADUATE_TAKE_PARAMETERES)
		:Student(HUMAN_GIVE_PARAMETERES, STUDENT_GIVE_PARAMETERES)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methods:
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << ", " << "предмет - " << get_subject();
	}
};


//#define INHERITANCE
#define Polymorphism

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Teacher teacher("white", "walter", 50, "chemistry", 25);
	teacher.info();

	Graduate graduate("danila", "debilovi4", 25, "nifiga nedelanie", "pv_521", 0, 0, "hz che");
	graduate.info();
#endif


	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98),
		new	Teacher("white", "walter", 50, "chemistry", 25),
		new Graduate("Debilovi4", "Danila", 25, "nifiga nedelanie", "pv_521", 0, 0, "OOP"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};
	cout << delimiter << endl;

	std::ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info(cout);
		fout << *group[i] << endl;
		cout << delimiter << endl;
	}
	fout.close();
	system("notepad group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}
}