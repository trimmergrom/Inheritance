#include <iostream>
#include <string>


class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;

public:
	const std::string& get_last_name()
	{
		return last_name;
	}
	const std::string& get_first_name()
	{
		return first_name;
	}
	unsigned int get_age()const
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
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		std::cout << last_name << " " << first_name << " " << age << " years\n";
	}
};
class Student :public Human
{
	std::string speciality;
	std::string group;
	float rating;
	float attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	float get_rating()const
	{
		return rating;
	}
	float get_attendance()const
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
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance
	)
		:Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Human::print();
		std::cout << speciality << " " << group << " " << rating << " " <<
			attendance << std::endl;
	}
	

};
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	Teacher(const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience)
		:Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
	}
	void print()
	{
		Human::print();
	std::cout << speciality << " " << experience << std::endl;

	}
};
class Graduate : public Student
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
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	void print()
	{
		Student::print();
		std::cout << subject << std::endl;
	}

};

#define INHERITANCE_CHECK
int main()
{
#ifdef INHERITANCE_CHECK
	Human human("James", "Bond", 18);
	human.print();
	Student student("James", "Bond", 18, "Chemistry", "WW_121", 90, 85);
	student.print();
	Teacher teacher("White", "Walter", 55, "Chemistry", 35);
	teacher.print();
	Graduate graduate("Scharder", "Hank", 40, "Chemister", "WW_121", 95, 55, "How to catch Heisenberg");
	graduate.print();
#endif // INHERITANCE_CHECK

}