#include"BaseClass.h"
#include"StudentClass.h"
#include"TeacherClass.h"
#include"GraduateClass.h"


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