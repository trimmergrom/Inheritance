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


	std::cout << "Radius = " << circle.get_radius() << " sm" << std::endl;
	std::cout << "Circle area = " << circle.figure_area(circle.get_radius()) << " sm2" << std::endl;
	std::cout << "Circumference = " << circle.circumference(circle.get_radius()) << " sm" << std::endl;

	std::vector <Point> pt;
	for (int i = 0; i < 36; i++)
	{
	Point point;
	pt.push_back(point);
	}
	std::cout << "The length is: " << pt.size() << '\n';
	
	for (int alfa = 0, i = 0; alfa < 360, i < 36; alfa += 10, i++)
	{
		pt.at(i) =   Point(circle.get_radius() * cos(alfa * 3.14 / 180), circle.get_radius() * sin(alfa * 3.14 / 180));
	}
	for (int i = 0; i < 36; i++)
	{
		std::cout << "Point " << i << " " << pt.at(i) << std::endl;
	}
		
	/*Point* group[] {
		new Point(circle.get_radius() * cos(0), circle.get_radius() * sin(0)),
		new Point(circle.get_radius() * cos(10*3.14/180), circle.get_radius() * sin(10*3.14/180)),
		new Point(circle.get_radius() * cos(20 * 3.14 / 180), circle.get_radius() * sin(20 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(30 * 3.14 / 180), circle.get_radius() * sin(30 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(40 * 3.14 / 180), circle.get_radius() * sin(40 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(50 * 3.14 / 180), circle.get_radius() * sin(50 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(60 * 3.14 / 180), circle.get_radius() * sin(60 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(70 * 3.14 / 180), circle.get_radius() * sin(70 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(80 * 3.14 / 180), circle.get_radius() * sin(80 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(90 * 3.14 / 180), circle.get_radius() * sin(90 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(100 * 3.14 / 180), circle.get_radius() * sin(100 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(110 * 3.14 / 180), circle.get_radius() * sin(110 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(120 * 3.14 / 180), circle.get_radius() * sin(120 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(130 * 3.14 / 180), circle.get_radius() * sin(130 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(140 * 3.14 / 180), circle.get_radius() * sin(140 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(150 * 3.14 / 180), circle.get_radius() * sin(150 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(160 * 3.14 / 180), circle.get_radius() * sin(160 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(170 * 3.14 / 180), circle.get_radius() * sin(170 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(180 * 3.14 / 180), circle.get_radius() * sin(180 * 3.14 / 180)),
		new Point(circle.get_radius() * cos(190 * 3.14 / 180), circle.get_radius() * sin(190 * 3.14 / 180)),
		
	};	

	for (int i = 0; i < sizeof(group)/sizeof(Point*); i++)
	{
		group[i]->print();
		
	}
	for (int i = 0; i < sizeof(group) / sizeof(Point*); i++)
	{
		delete group[i];
	}*/
}

