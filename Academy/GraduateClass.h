#include"BaseClass.h"

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
		this->average_score = (scores_of_theory + scores_of_practice) / 2;
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
		cout << "Тема дипломной работы - " << theme_of_work << ", " << "Дата защиты диплома - " << date_of_diploma_defense << ", " << "Баллы за практику - " << scores_of_practice << ", " << "Баллы за теорию - " << scores_of_theory << ", " << "Средний балл - " << average_score << endl;
	}
};
