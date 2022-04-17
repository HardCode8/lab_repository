#pragma once
#include <cmath>
/* ��
	�� ����� ����� � ���������� ����������� ������:
	������������� �� ����� ��� �������-����� � ������������ ��������.
	������������� �������� ����� � ��������. ��� ��������, ��� ���� �� ������ �������, ������� ������� ���������.
	�������� ����� ������� ����� � ��������.
	�������� ������� ���� �� ������� ������ ����� � ��������.
		���� Triangle
		�� ������� ����� 
		1.��������� ������ ��� ����� ���������� �� ���������(+)
		2.��������� ������ ��� ����� ���������� � ����� ������� ����(*)
		3.������ �� �-� ������� ����������("[]")
		4. ���������� �� ������� ����(��������� ���� �����)
		�� �����-�������
		��������� ���������� � �����("<<")
		��������� ���������� �� �����(">>")
		������(">")
		�����("<")
		г���("==")(��� �������� ���������� ����� ����������)
		�������� �������� ����, � ����� � �������� ���������� ��� ������� ���������� ��'����, � ����� ������� ������� ��� ������ � ��� �����.
*/


class Triangle
{
	double sideA;
	double sideB;
	double sideC;
	static int howManyTriangles;

public:

	Triangle();
	Triangle(const double inputSideA, const double inputSideB, const double inputSideC);
	Triangle(const Triangle& copyTriangle);
	~Triangle();

	double perimetr() const;
	double square() const;
	void increaseByConst(const double increseValue);
	void setSides(const double sideA, const double sideB, const double sideC);
	void getSides(double& sideA, double& sideB, double& sideC) const;
	void corners(double& cornerA, double& cornerB, double& cornerC) const;
	void findHeights(double& heighA, double& heighB, double& heighC) const;
	bool isRectangular() const;
	static int howMany();

	void operator+(const double increaseValue);
	void operator*(const double increaseValue);
	double& operator[](const int index);
	const double& operator[](const int index) const;
	operator double() const;

	friend bool operator <(const Triangle& leftTriangle, const Triangle& rightTriangle);
	friend bool operator >(const Triangle& leftTriangle, const Triangle& rightTriangle);
	friend bool operator==(const Triangle& leftTriangle, const Triangle& rightTriangle);
};


bool operator <(const Triangle& leftTriangle, const Triangle& rightTriangle);
bool operator >(const Triangle& leftTriangle, const Triangle& rightTriangle);
bool operator==(const Triangle& leftTriangle, const Triangle& rightTriangle);