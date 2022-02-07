#include <iostream>
#include "Point.h"

class Geometric_figures
{
	double figure_area;
public:
	virtual void move() = 0;
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
	Point** circle_out(const double& radius)
	{		
		Point** circle_out = new Point* [36]{};
		for (int alfa = 0, i=0; alfa < 360; alfa + 10)
		{
			circle_out[i] = new Point (radius * cos(alfa), radius * sin(alfa));
		}		
		return circle_out;
	}
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


int main()
{

	Square square;
	square.move();
	Circle circle;
	circle.move();
	
	double x;
	srand(3);	
	x = (double)rand()/10;	
	circle.set_radius(x);

	
	std::cout << "Radius = " << circle.get_radius() << " sm" << std::endl;
	std::cout << "Circle area = " << circle.figure_area(circle.get_radius()) <<  " sm2" << std::endl;
	std::cout << "Circumference = " << circle.circumference(circle.get_radius()) << " sm" << std::endl;
	
	Point** group =	circle.circle_out(circle.get_radius());
	for (int i = 0; i < 36; i++)
	{
		group[i]->print();
		std::cout << "\n--------------------\n";
	}	
}

