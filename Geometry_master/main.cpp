#include<iostream>
using namespace std;

enum Color
{
	Red = 0x000000FF,
	Green = 0x0000FF00,
	Blue = 0x00FF0000,
	Yellow = 0x0000FFFF,
	Orange = 0x0000A5FF,
	White = 0x00FFFFFF
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color) {/*Telo constructora*/ }
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
	virtual void info()const
	{
		cout << "Площадь фигуры: " << get_area() << endl;
		cout << "Периметр фигуры: " << get_perimeter() << endl;
		draw();
	}

};

class Square :public Shape
{
	double side;
public:
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return 4 * side;
	}
	void draw()const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны квадрата: " << get_side() << endl;
		Shape::info();
	}
};

class Pryamougolbnik :public Shape
{
	double LONG_side;
	double SHORT_side;
public:
	Pryamougolbnik(double LONG_side, double SHORT_side, Color color) :Shape(color)
	{
		set_long_side(LONG_side);
		set_short_side(SHORT_side);
	}
	double get_long_side()const
	{
		return LONG_side;
	}
	void set_long_side(double LONG_side)
	{
		this->LONG_side = LONG_side;
	}
	double get_short_side()const
	{
		return SHORT_side;
	}
	void set_short_side(double SHORT_side)
	{
		this->SHORT_side = SHORT_side;
	}
	double get_area()const override
	{
		return LONG_side * SHORT_side;
	}
	double get_perimeter()const override
	{
		return 2 * (LONG_side + SHORT_side);
	}
	void draw()const override
	{
		for (int i = 0; i < LONG_side; i++)
		{
			for (int j = 0; j < SHORT_side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Большая сторона прямоугольника: " << get_long_side() << endl;
		cout << "Меньшая сторона прямоугольника: " << get_short_side() << endl;
		Shape::info();
	}
};

class Equilateral_triangle :public Shape
{
	double side;
	double Triangle_h;
public:
	Equilateral_triangle(double side, Color color) :Shape(color)
	{
		set_side(side);
		Triangle_h = (sqrt(3) * side) / 2;
	}
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_area()const override
	{
		return 0.5 * side * Triangle_h;
	}
	double get_perimeter()const override
	{
		return 3 * side;
	}
	void draw()const override
	{
		for (int i = 0; i <= side-1; i++)
		{
			for (int j = side; j >= 1; j--)
			{
				if (i == side - 1 || j == i)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			for (int j = 0; j <= side - 1; j++)
			{
				if (i == side - 1)
				{
					cout << "* ";
				}
				else if (j == i && i != 4)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
		cout << endl;
		
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Сторона равностороннего треугольника: " << get_side() << endl;
		Shape::info();
	}
};

class Triangle :public Shape
{
	double katet_1;
	double katet_2;
	double gipotenuza;
public:
	Triangle(double katet_1, double katet_2, Color color) :Shape(color)
	{
		set_katet_1(katet_1);
		set_katet_2(katet_2);
		gipotenuza = sqrt((katet_1 * katet_1) + (katet_2 * katet_2));
	}
	double get_katet_1()const
	{
		return katet_1;
	}
	void set_katet_1(double katet_1)
	{
		this->katet_1 = katet_1;
	}
	double get_katet_2()const
	{
		return katet_2;
	}
	void set_katet_2(double katet_2)
	{
		this->katet_2 = katet_2;
	}
	double get_area()const override
	{
		int p = (katet_1 + katet_2 + gipotenuza) / 2;
		return sqrt(p * (p - katet_1) * (p - katet_2) * (p - gipotenuza));
	}
	double get_perimeter()const override
	{
		return katet_1+katet_2+gipotenuza;
	}
	void draw()const override
	{
		for (int i = 0; i < katet_2/(katet_2/katet_1); i++)
		{
			if ((katet_2 / katet_1) / 2 == 1)
			{
				for (int j = 0; j <= i * (katet_2 / katet_1) + 1; j++)
				{
					cout << "* ";
				}
			}
			else
			{
				for (int j = 0; j <= i * (katet_2 / katet_1); j++)
				{
					cout << "* ";
				}
			}
			cout << endl;
		}

	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Катет треугольника: " << get_katet_1() << endl;
		cout << "Катет треугольника: " << get_katet_2() << endl;
		Shape::info();
	}
};

class Circle :public Shape
{
	double radius;
	double diameter;
	double p;
public:
	Circle(double radius, Color color) :Shape(color)
	{
		set_radius(radius);
		p = 3.14;
	}
	double get_radius()const
	{
		return radius;
	}
	void set_radius(double radius)
	{
		this->radius = radius;
	}
	double get_diameter()const
	{
		return radius*2;
	}
	void set_diameter(double diameter)
	{
		this->diameter = diameter;
	}
	double get_area()const override
	{
		return p*(radius*radius);
	}
	double get_perimeter()const override
	{
		return 2*p*radius;
	}
	void draw()const override
	{
		cout << "Nu eto ne smeshno, eto nikak ne vbIvesti na ekran";
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Радиус: " << get_radius() << endl;
		cout << "Диаметр: " << get_diameter() << endl;
		Shape::info();
	}
};

//#define squirrel //белка
//#define tupougolbnik
//#define triangulyarnaya_singulyarnostb
//#define Tri_Angle		//Какой же стрём вышел XD
#define Circle_Pit

void main()
{
	setlocale(LC_ALL, "");
#ifdef squirrel
	//Shape shape(Color::Red);
	Square square(5, Color::Red);
	cout << "Длина стороны квадраты:" << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	cout << "\n-------------------------------\n" << endl;
	square.info();
#endif

#ifdef tupougolbnik
	Pryamougolbnik pryamougolbnik(5, 10, Color::Red);
	pryamougolbnik.info();
#endif

#ifdef triangulyarnaya_singulyarnostb
	Equilateral_triangle triangle(5, Color::Red);
	triangle.info();
#endif

#ifdef Tri_Angle
	Triangle triangle(5, 10, Color::Red);
	triangle.info();
#endif

#ifdef Circle_Pit
	Circle circle(5, Color::Red);
	circle.info();
#endif
}