#pragma once
#include"stdafx.h"

#define ANIMALS_TAKE_PARAMETERS const std::string& type, const std::string& klass, const std::string& squad, const std::string& family, const std::string& genus, const std::string& kind, const std::string& habitat, int quantity_in_Zoo
#define ANIMALS_GIVE_PARAMETERS type, klass, squad, family, genus, kind, habitat, quantity_in_Zoo

class Animals
{
	std::string type;		//Тип
	std::string klass;		//Класс
	std::string squad;		//Отряд
	std::string family;		//Семейство
	std::string genus;		//Род
	std::string kind;		//Вид
	std::string habitat;	//Ареал обитания
	int quantity_in_Zoo;	//Количество обитающих в зоопарке
public:
	const std::string& get_type()const
	{
		return type;
	}
	const std::string& get_klass()const
	{
		return klass;
	}
	const std::string& get_squad()const
	{
		return squad;
	}
	const std::string& get_family()const
	{
		return family;
	}
	const std::string& get_genus()const
	{
		return genus;
	}
	const std::string& get_kind()const
	{
		return kind;
	}
	const std::string& get_habitat()const
	{
		return habitat;
	}
	int get_quantity_in_Zoo()const
	{
		return quantity_in_Zoo;
	}
	void set_type(const std::string& type)
	{
		this->type = type;
	}
	void set_klass(const std::string& klass)
	{
		this->klass = klass;
	}
	void set_squad(const std::string& squad)
	{
		this->squad = squad;
	}
	void set_family(const std::string& family)
	{
		this->family = family;
	}
	void set_genus(const std::string& genus)
	{
		this->genus = genus;
	}
	void set_kind(const std::string& kind)
	{
		this->kind = kind;
	}
	void set_habitat(const std::string& habitat)
	{
		this->habitat = habitat;
	}
	void set_quantity_in_Zoo(int quantity_in_Zoo)
	{
		this->quantity_in_Zoo = quantity_in_Zoo;
	}
	//				Constructors:
	Animals(ANIMALS_TAKE_PARAMETERS)
	{
		set_type(type);
		set_klass(klass);
		set_squad(squad);
		set_family(family);
		set_genus(genus);
		set_kind(kind);
		set_habitat(habitat);
		set_quantity_in_Zoo(quantity_in_Zoo);
		cout << "AConstructor:\t" << this << endl;
	}
	virtual ~Animals()
	{
		cout << "ADestructor:\t" << this << endl;
	}
	//				Methods:
	virtual void info()const
	{
		cout << "Тип - " << type << ", " << "Класс - " << klass << ", " << "Отряд - " << squad << ", " << "Семейство - " << family << ", " << "Род - " << genus << "," << "\n" << "Вид - " << kind << ", "  << "Ареал обитания - " << habitat << ", " << "Количество проживающих в зоопарке - " << quantity_in_Zoo << endl;
	}
};
