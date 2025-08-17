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
	Data(DATA_TAKE_PARAMETERS)
	{
		for (int i = 0; i <= Month + Day/31; i++)
		{
			if (Month % 12 == 1 || Month % 12 == 3 || Month % 12 == 5 || Month % 12 == 7 || Month % 12 == 8 || Month % 12 == 10 || Month % 12 == 12 || (Month + Day / 31) % 12 == 2 || (Month + Day / 31) % 12 == 4 || (Month + Day / 31) % 12 == 6 || (Month + Day / 31) % 12 == 9 || (Month + Day / 31) % 12 == 11)
			{
				if (Month + Day/31 > 12 && Day >= 365)
				{
					Year = Year + Month / 12 + Day / 365;
					Month = Month % 12;
					Day = (Day % 365)%31;
				}
				if (Day >= 365)
				{
					Year = Year + Day / 365;
					Month = Month + Day % 365 / 30;
					if (Month > 12)
					{
						Month = Month % 12;
					}
					Day = (Day % 365) % 31;
				}
				if ((Month % 12 + Day / 31) > 12)
				{
					Year = Year + Month / 12 + (Month % 12 + Day / 31) / 12;
					Month = (Month % 12 + Day / 31) % 12;
					Day = Day % 31;
				}
				else
				{
					Month = Month % 12 + Day / 31;
					if (Month == 0)
					{
						Month = 12;
					}
					Day = Day % 31;
				}
			}
			else
			{
				if (Month + Day / 30 > 12 && Day >= 365)
				{
					Year = Year + (Month / 12) + Day / 365;
					Month = Month % 12;
					Day = (Day % 365) % 30;
				}
				if (Day >= 365)
				{
					Year = Year + Day / 365;
					Month = Month + Day % 365 / 30;
					if (Month > 12)
					{
						Month = Month % 12;
					}
					Day = (Day % 365) % 30;
				}
				if ((Month % 12 + Day / 30) > 12)
				{
					Year = Year + Month / 12 + (Month % 12 + Day / 30) / 12;
					Month = (Month % 12 + Day / 30) % 12;
					Day = Day % 30;
				}
				else
				{
					Month = (Month % 12 + Day / 30);
					if(Month == 0)
					{
						Month = 12;
					}
					Day = Day % 30;
				}
			}
		}
		set_Day(Day);
		set_Month(Month);
		set_Year(Year);
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