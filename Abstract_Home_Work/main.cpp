#include <iostream>
#include <vector>
#include "Point.h"

class Geometric_figures
{
	double figure_area;
public:
	virtual void move() = 0;
};
class Square
{
	double side;
public:
	void move()
	{
		std::cout << "Square" << std::endl;
	}		
};

class Circle :public Geometric_figures
{
	double radius;
public:
	void move()
	{
		std::cout << "Circle" << std::endl;
	}
	double get_radius()const
	{
		return radius;
	}
	void set_radius(double radius)
	{
		this->radius = radius;
	}	
	double figure_area(const double& radius)
	{
		return 3.14 * pow(radius, 2) / 2;
	}
	double circumference(const double& radius)
	{
		return 2 * 3.14 * radius;
	}
	
};

int main()
{

	Square square;
	square.move();
	Circle circle;
	circle.move();

	double x;
	srand(6);
	x = (double)rand() / 10;
	circle.set_radius(x);

	std::cout << "\n--------------------CIRCLE-------------------------------\n";
	std::cout << "Radius = " << circle.get_radius() << " sm" << std::endl;
	std::cout << "Circle area = " << circle.figure_area(circle.get_radius()) << " sm2" << std::endl;
	std::cout << "Circumference = " << circle.circumference(circle.get_radius()) << " sm" << std::endl << std::endl;

	std::vector <Point> pt;
	for (int i = 0; i < 36; i++)
	{
	Point point;
	pt.push_back(point);
	}
	std::cout << "The length is: " << pt.size() << '\n';
	
	/*for (int alfa = 0, i = 0; alfa < 360, i < 36; alfa += 10, i++)
	{
		pt.at(i) =   Point(circle.get_radius() * cos(alfa * 3.14 / 180), circle.get_radius() * sin(alfa * 3.14 / 180));
	}*/
	for (int i = 0; i < 36; i++)
	{
		pt.at(i) =   Point(circle.get_radius() * cos((i*10) * 3.14 / 180), circle.get_radius() * sin((i*10) * 3.14 / 180));
	}

	for (int i = 0; i < 36; i++)
	{
		std::cout << "Point " << i << "  " << pt.at(i) << std::endl;
	}		
}

