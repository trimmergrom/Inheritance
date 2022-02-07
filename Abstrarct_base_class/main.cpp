#include<iostream>
using namespace std;

class Vehicle	//������������ ��������
{
	unsigned int speed;
public:
	virtual void move() = 0;//����� ����������� �����, �� ������ ����� �����������.
};

class GroundVehicle :public Vehicle //�������� ���������� ��������
{

};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "������ ���� �� 4� �������" << endl;
	}
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "������� ���� �� 2� �������" << endl;
	}
};

class AirVehicle :public Vehicle
{
	double height;
};
class Plain :public AirVehicle
{
public:
	void move()
	{
		cout << "������� ����� � ������� ���������, �� ��� ��� ������� � ������� ����� �������� ������" << endl;;
	}
};
class Helicopter :public AirVehicle
{
public:
	void move()
	{
		cout << "�������� �������� � �����, �� ������������ �� ��������� ��������" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;	//���������� ������� ��������� ������������ ������
	//GroundVehicle car;

	Car bmw;
	bmw.move();

	Bike HarleyDevidson;
	HarleyDevidson.move();

	Plain boeing;
	boeing.move();

	Helicopter apache;
	apache.move();
}

//virtual type name() = 0;
//virtual type name()const = 0;