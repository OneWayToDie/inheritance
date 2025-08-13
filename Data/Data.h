#pragma once
#include"stdafx.h"


class Data
{
	int Year;
	int Month;
	int Day;
public:
	int get_Day()const
	{
		return Day;
	}
	int get_Month()const
	{
		return Month;
	}
	int get_Year()const
	{
		return Year;
	}
	void set_Day(int Day)
	{
		this->Day = Day;
	}
	void set_Month(int Month)
	{
		this->Month = Month;
	}
	void set_Year(int Year)
	{
		this->Year = Year;
	}
	//			Constructors:
	Data(DATA_TAKE_PARAMETERES)
	{
		if (Month > 12 || Day > 30)
		{
			if ((Month % 12 + Day / 30) > 12)
			{
				set_Day(Day % 30);
				set_Month((Month % 12 + Day / 30) % 12);
				set_Year(Year + Month / 12 + (Month % 12 + Day / 30) / 12);
			}
			else
			{
				set_Day(Day % 30);
				set_Month(Month % 12 + Day / 30);
				set_Year(Year + Month / 12);
			}
		}
		else
		{
			set_Day(Day);
			set_Month(Month);
			set_Year(Year);
		}
		cout << "Constructor:\t" << this << endl;
	}
	Data(int Year)
	{
		this->Year = Year;
		set_Month(Month);
		set_Day(Day);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Data(int Month, int Year)
	{
		set_Year(Year);
		this->Month = Month;
		set_Day(Day);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Data()
	{
		set_Year(Year);
		set_Month(Month);
		this->Day = Day;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Data(const Data& other)
	{
		this->Year = other.Year;
		this->Month = other.Month;
		this->Day = other.Day;
		cout << "CopyConstructor:\t" << this << endl;
	}
	Data& operator=(const Data& other)
	{
		this->Year = other.Year;
		this->Month = other.Month;
		this->Day = other.Day;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	virtual ~Data()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Methods:
	virtual std::ostream& prinimaemaya_data(std::ostream& os)const
	{
		return os << "Год - " << Year << " Месяц - " << Month << " День - " << Day << endl;
	}
};


std::ostream& operator<<(std::ostream& os, const Data& obj)
{
	return obj.prinimaemaya_data(os);
}
Data operator+(const Data& left, Data right)
{
	return Data
	(
		left.get_Year() + right.get_Year(),
		left.get_Month() + right.get_Month(),
		left.get_Day() + right.get_Day()
	);
}
Data operator-(const Data& left, Data right)
{
	return Data
	(
		left.get_Year() - right.get_Year(),
		left.get_Month() - right.get_Month(),
		left.get_Day() - right.get_Day()
	);
}