#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------------------------------------------------------------------------\n"
#define Nolimiter "\n__________________________________________________________________________________________________________________________________\n"

#define HUMAN_TAKE_PARAMETERES const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERES last_name, first_name, age


class Human
{
	static const int TYPE_WIDTH = 12;
	static const int NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count;	//Объвление статической переменной
	std::string last_name;
	std::string first_name;
	int age;
public:
	static int get_count()
	{
		return count;
	}
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
		count++;
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor:\t" << this << endl;
	}

	//					Methods:
	virtual std::ostream& info(std::ostream& os)const	// BaseClass
	{
		os.width(TYPE_WIDTH);	// Метод width(N) задает размер поля, в которое будет выведено значение
		os << std::left;
		os << std::string(strchr(typeid(*this).name(), ' ') + 1);
		os << "|";
		//strchr(const char* str, char symbol); 
		//strchr() в указанной строке находит указанный символ,
		// И вовзвращает указатель на найденный символ, или 'nullptr',
		// если указанный символ отсутствует в указанной строке.
		// class Student;
		//return os << "Фамилия - " << last_name << ", " << "Имя - " << first_name << ", " << "Возраст - " << age << "  ";
		os.width(NAME_WIDTH);
		os << last_name;
		os << "|";
		os.width(NAME_WIDTH);
		os << first_name;
		os << "|";
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}
};

int Human::count = 0;	//Инициализация статической переменной (относится к определению класса - Class definition)

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}

#define STUDENT_TAKE_PARAMETERES  const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERES  speciality, group, rating, attendance

class Student:public Human
{
	static const int SPECIALITY_WIDTH = 32;
	static const int GROUP_WIDTH = 8;
	static const int RAT_WIDTH = 8;
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
		//return Human::info(os) << "Специальность - " << speciality << ", " << "Номер группы - " << group << ", " << "Рейтинг - " << rating << ", " << "Успеваемость - " << attendance;
		Human::info(os);
		os << "|";
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os << "|";
		os.width(GROUP_WIDTH);
		os << group;
		os << "|";
		os.width(RAT_WIDTH);
		os << rating;
		os << "|";
		os.width(RAT_WIDTH);
		os << attendance;
		os << std::right;
		os.width(5);
		os << "|";
		os << std::right;
		os.width(11);
		os << "|";
		return os;
	}
};

#define TEACHER_TAKE_PARAMETERES const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERES speciality, experience

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 32;
	static const int EXPERIENCE_WIDTH = 2;
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
		//return Human::info(os) << "Специальность - " << speciality << ", " << "опыт работы - " << experience;
		Human::info(os);
		os << "|";
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os << "|";
		os.width(9);
		os << std::right;
		os << "|";
		os.width(9);
		os << std::right;
		os << "|";
		os.width(13);
		os << std::right;
		os << "|";
		os.width(EXPERIENCE_WIDTH);
		os << experience;
		os.width(9);
		os << std::right;
		os << "|";
		return os;
	}
};


#define GRADUATE_TAKE_PARAMETERES const std::string& subject
#define GRADUATE_GIVE_PARAMETERES subject

class Graduate :public Student
{
	static const int SUBJECT_WIDTH = 8;
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
		//return Student::info(os) << ", " << "предмет - " << get_subject();
		Student::info(os);
		os << std::left;
		os.width(SUBJECT_WIDTH);
		os << subject;
		return os;
	}
};

#define TYPE_GROUP_TAKE_PARAMETERS const std::string Last_name, const std::string First_name, const std::string Age, const std::string Speciality, const std::string Group, const std::string Rating, const std::string Attendance, const std::string Experience, const std::string Subject

class Type_group
{
	static const int TYPE_WIDTH = 12;
	static const int NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static const int SPECIALITY_WIDTH = 32;
	static const int GROUP_WIDTH = 8;
	static const int RAT_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 12;
	static const int EXPERIENCE_WIDTH = 5;
	static const int SUBJECT_WIDTH = 10;
	std::string Last_name;
	std::string First_name;
	std::string Age;
	std::string Speciality;
	std::string Group;
	std::string Rating;
	std::string Attendance;
	std::string Subject;
	std::string Experience;
public:
	const std::string& get_Last_name()const
	{
		return Last_name;
	}
	const std::string& get_First_name()const
	{
		return First_name;
	}
	const std::string& get_Age()const
	{
		return Age;
	}
	const std::string& get_Speciality()const
	{
		return Speciality;
	}
	const std::string& get_Group()const
	{
		return Group;
	}
	const std::string& get_Rating()const
	{
		return Rating;
	}
	const std::string& get_Attendance()const
	{
		return Attendance;
	}
	const std::string& get_Experience()const
	{
		return Experience;
	}
	const std::string& get_Subject()const
	{
		return Subject;
	}
	void set_Last_Name(const std::string& Last_name)
	{
		this->Last_name = Last_name;
	}
	void set_First_Name(const std::string& First_name)
	{
		this->First_name = First_name;
	}
	void set_Age(const std::string& Age)
	{
		this->Age = Age;
	}
	void set_Speciality(const std::string& Speciality)
	{
		this->Speciality = Speciality;
	}
	void set_Group(const std::string& Group)
	{
		this->Group = Group;
	}
	void set_Rating(const std::string& Rating)
	{
		this->Rating = Rating;
	}
	void set_Attendance(const std::string& Attendance)
	{
		this->Attendance = Attendance;
	}
	void set_experience(const std::string& Experience)
	{
		this->Experience = Experience;
	}
	void set_subject(const std::string& Subject)
	{
		this->Subject = Subject;
	}
	//		Constructors:
	Type_group(TYPE_GROUP_TAKE_PARAMETERS)
	{
		set_Last_Name(Last_name);
		set_First_Name(First_name);
		set_Age(Age);
		set_Speciality(Speciality);
		set_Group(Group);
		set_Rating(Rating);
		set_Attendance(Attendance);
		set_experience(Experience);
		set_subject(Subject);
		cout << "TgConstructor:\t" << this << endl;
	}
	virtual ~Type_group()
	{
		cout << "TgDestructor:\t" << this << endl;
	}
	//		Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		os.width(TYPE_WIDTH);
		os << std::left;
		os << std::string(strchr(typeid(*this).name(), ' ') + 1);
		os << "|";
		os.width(NAME_WIDTH);
		os << Last_name;
		os << "|";
		os.width(NAME_WIDTH);
		os << First_name;
		os << "|";
		os.width(AGE_WIDTH);
		os << Age;
		os << "|";
		os.width(SPECIALITY_WIDTH);
		os << Speciality;
		os << "|";
		os.width(GROUP_WIDTH);
		os << Group;
		os << "|";
		os.width(RAT_WIDTH);
		os << Rating;
		os << "|";
		os.width(ATTENDANCE_WIDTH);
		os << Attendance;
		os << "|";
		os.width(EXPERIENCE_WIDTH);
		os << Experience;
		os << "|";
		os.width(SUBJECT_WIDTH);
		os << Subject;
		return os;
	}
};

std::ostream& operator<<(std::ostream& os, const Type_group& obj)
{
	return obj.info(os);
}

void Print(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		group[i]->info(cout);
		//cout << delimiter << endl;
	}
	cout << "Количество объектов: " << Human::get_count() << endl;
}

void Print_type_group(Type_group* zagolovok_tablicbI[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		zagolovok_tablicbI[i]->info(cout);
		/*cout << delimiter << endl;*/
	}
}

void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());	//Метод c_str() возвращает строку в виде массива символов (char* );
}
void Save_type_group(Type_group* zagolovok_tablicbI[], Human* group[], const int n, const int d, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *zagolovok_tablicbI[i] << endl;
		/*fout << Nolimiter << endl;*/
	}
	for (int i = 0; i < d; i++)
	{
		fout << *group[i] << endl;
		/*fout << Nolimiter << endl;*/
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());	//Метод c_str() возвращает строку в виде массива символов (char* );
}

Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//1) Подсчитываем количество объектов в файле:
		n = 0;
		std::string buffer;
		/*while (!fin.eof())*/
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.size() < 32)continue;
			n++;
		}
		cout << "Количество объектов: " << n << endl;

		//2) Выделяем память под объекты:
		group = new Human * [n];

		//3)Возвращаемся в начало файла, для того чтобы прочитать из него сами объекты:
		cout << "Position " << fin.tellg() << endl; //Метод tellg() возвращает текущую Get-позицию курсора на чтение.
		fin.clear();
		fin.seekg(0);	//Метод seekg(n), переводит Get-курсор (на чтение) в указанную позицию 'n';
		cout << "Position " << fin.tellg() << endl;

	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	//?) Закрываем файл:
	fin.close();

	return group;
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}
}

//#define INHERITANCE
//#define POLYMORPHISM
//#define LoadGroup
#define Read_group

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

#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98),
		new	Teacher("white", "walter", 50, "chemistry", 25),
		new Graduate("Debilovi4", "Danila", 25, "nifiga nedelanie", "pv_521", 0, 0, "OOP"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};
	Type_group* zagolovok_tablicbI[] =
	{
		new Type_group("Last Name","First Name", "Age", "Speciality", "Group", "Rating", "Attendance", "Experience", "Subject")
	};


	Print_type_group(zagolovok_tablicbI, sizeof(zagolovok_tablicbI) / sizeof(zagolovok_tablicbI[0]));
	Print(group, sizeof(group) / sizeof(group[0]));
	Save_type_group(zagolovok_tablicbI, group, sizeof(zagolovok_tablicbI) / sizeof(zagolovok_tablicbI[0]), sizeof(group) / sizeof(group[0]), "group.txt");


	for (int i = 0; i < sizeof(zagolovok_tablicbI) / sizeof(zagolovok_tablicbI[0]); i++)
	{
		delete zagolovok_tablicbI[i];
		/*cout << delimiter << endl;*/
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		/*cout << delimiter << endl;*/
	}
#endif

#ifdef LoadGroup
	std::ifstream fin("group.txt");

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fin.close();
#endif

#ifdef Read_group
	int n = 0;
	Human** group = Load("group.txt", n);


	Print(group, n);
	Clear(group, n);
#endif
}