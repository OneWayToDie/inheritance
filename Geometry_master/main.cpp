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
	//Triangle_h(double side, Color color) :Shape(color)
	//{
	//	Triangle_h = (sqrt(3) * side) / 2;
	//}
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
		for (int i = side; i <= side; i++)
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
		cout << "Сторона равностороннего треугольника: " << get_side() << endl;
		Shape::info();
	}
};

//#define squirrel //белка
//#define tupougolbnik
#define triangulyarnaya_singulyarnostb

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
}