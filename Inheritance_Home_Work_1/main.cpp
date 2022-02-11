#include <iostream>
#include <string>
#include <Windows.h>

#define DEBUG
class Employee
{
protected:
	std::string rang;
	std::string last_name;
	std::string first_name;
	std::string rate;

public:
	const std::string& get_rang()const
	{
		return rang;
	}
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const std::string& get_rate()const
	{
		return rate;
	}
	void set_rang(const std::string& rang)
	{
		this->rang = rang;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_rate(const std::string& rate)
	{
		this->rate = rate;
	}

	Employee(const std::string& rang, const std::string& last_name, const std::string& first_name, const std::string& rate)
	{
		set_rang(rang);
		set_last_name(last_name);
		set_first_name(first_name);
		set_rate(rate);
#ifdef DEBUG
		std::cout << "EmpConstructor:\t" << this << std::endl;
#endif // DEBUG
	}

	virtual ~Employee()
	{
#ifdef DEBUG
		std::cout << "EmpDestructor:\t" << this << std::endl;
#endif // DEBUG
	}

	virtual void print()const
	{
		std::cout << rang << " " << last_name << " " << first_name << " " << rate << " ";
	}
};

class ID_number :public Employee
{
	unsigned int ID;

public:
	const unsigned int get_ID()const
	{
		return ID;
	}
	void set_ID(const unsigned  int ID)
	{
		this->ID = ID;
	}

	ID_number(const unsigned int ID, const std::string& rang, const std::string& last_name, const std::string& first_name,
		const std::string& rate) :Employee(rang, last_name, first_name, rate)
	{
		set_ID(ID);
#ifdef DEBUG
		std::cout << "IDConstructor:\t" << this << std::endl;
#endif // DEBUG
	}
	
	~ID_number()
	{
#ifdef DEBUG
		std::cout << "ID_Destructor:\t" << this << std::endl;
#endif // DEBUG
	}
	
	void print()const
	{
		std::cout << "ID " << ID << " ";
		Employee::print();
	}
};

class Report_card :public ID_number
{
	unsigned int work_days;
	float permaneted_rate;
	float hourly_rate;
	

public:
	const unsigned int get_work_days()const
	{
		return work_days;
	}
	const float get_permaneted_rate()const
	{
		return permaneted_rate;
	}
	const float get_hourly_rate()const
	{
		return hourly_rate;
	}
	void set_work_days(const unsigned int work_days)
	{
		this->work_days = work_days;
	}
	void set_permaneted_rate(const float permaneted_rate)
	{
		this->permaneted_rate = permaneted_rate;
	}
	void set_hourly_rate(const float hourly_rate)
	{
		this->hourly_rate = hourly_rate;
	}

	Report_card(const unsigned int ID, const std::string& rang, const std::string& last_name, const std::string& first_name,
	const std::string& rate,  const unsigned int work_days, const float permaneted_rate, const float hourly_rate)
	:ID_number(ID, rang, last_name, first_name, rate)
	{
		set_work_days(work_days);
		set_permaneted_rate(permaneted_rate);
		set_hourly_rate(hourly_rate);
#ifdef DEBUG
		std::cout << "Rpc_Constructor:\t" << this << std::endl;
#endif // DEBUG
	}

	~Report_card()
	{
#ifdef DEBUG
		std::cout << "Rpc_Destructor:\t" << this << std::endl;
#endif // DEBUG
	}
	float cash()const
	{	
		if (rate == "Permaneted") return (permaneted_rate / 24) * work_days;	
		else return hourly_rate* work_days * 8;	
	}
	void print()const
	{
		ID_number::print();
		if (rate == "Permaneted") { std::cout << work_days << " days\t" << permaneted_rate << " $/month\t" << cash() << " $" << std::endl; }
		else { std::cout << work_days << " days\t" << hourly_rate << " $/hour\t" << cash() << " $" << std::endl; }	
	}
};

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	Report_card* group[] =
	{
		new Report_card(1001, "Chif_of_departament", "Shakal", "Karlos", "Permaneted", 23, 3000, 0),
		new Report_card(1002, "Manager_1", "Willis", "Brus", "Hourly", 12, 0, 48),
		new Report_card(1003, "Manager_2", "Khary", "Mata", "Permaneted", 18, 2500, 0),
		new Report_card(1004, "Spec_1", "Zhirinovsky", "Vovan", "Hourly", 5, 0, 3)		
	};
	std::cout << "\n------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Report_card*); i++)
	{
		//group[i]->print();
		std::cout << group[i] << std::endl;
		std::cout << "\n------------------------------------------\n";
	}
	
	float Summ = 0;
	for (int i = 0; i < sizeof(group) / sizeof(Report_card*); i++)
	{
		Summ += group[i]->cash();
	}
	std::cout << "Departament payroll = " << Summ << " $" << std::endl;
	for (int i = 0; i < sizeof(group) / sizeof(Report_card*); i++)
	{
		delete group[i];
	}
}