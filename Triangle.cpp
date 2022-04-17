#include "Triangle.h"

int Triangle::howManyTriangles = 0;

Triangle::Triangle()
	:sideA(0), sideB(0), sideC(0) {	++howManyTriangles;}

Triangle::Triangle(const double inputSideA, const double inputSideB, const double inputSideC)
	: sideA(inputSideA), sideB(inputSideB), sideC(inputSideC) {++howManyTriangles;}

Triangle::Triangle(const Triangle& copyTriangle)
	:sideA(copyTriangle.sideA), sideB(copyTriangle.sideB), sideC(copyTriangle.sideC){++howManyTriangles;}


Triangle::~Triangle()
{
	--howManyTriangles;
}


double Triangle::perimetr() const
{
	return sideA + sideB + sideC;
}


double Triangle::square() const
{
	double halfOfPerimetr = perimetr() * 0.5;

	return sqrt(halfOfPerimetr * (halfOfPerimetr - sideA) * (halfOfPerimetr - sideB) * (halfOfPerimetr - sideC));
}


void Triangle::increaseByConst(const double increaseValue)
{
	sideA += increaseValue;
	sideB += increaseValue;
	sideC += increaseValue;
}


void Triangle::setSides(const double sideA, const double sideB, const double sideC)
{
	this->sideA = sideA;
	this->sideB = sideB;
	this->sideC = sideC;
}


void Triangle::getSides(double& sideA, double& sideB, double& sideC) const
{
	sideA = this->sideA;
	sideB = this->sideB;
	sideC = this->sideC;
}


void Triangle::corners(double& cornerA, double& cornerB, double& cornerC) const
{
	double PI = 3.14159265358979;
	double cosOfSide = (sideA * sideA + sideB * sideB - sideC * sideC) / (2 * sideA * sideB);
	cornerA = acos(cosOfSide) * (180 / PI);

	cosOfSide = (sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC);
	cornerB = acos(cosOfSide) * (180 / PI);

	cosOfSide = (sideA * sideA + sideC * sideC - sideB * sideB) / (2 * sideA * sideC);
	cornerC = acos(cosOfSide) * (180 / PI);
}


void Triangle::findHeights(double& heighA, double& heighB, double& heighC) const
{
	heighA = (2 * square()) / (sideB * sideC);
	heighB = (2 * square()) / (sideA * sideC);
	heighC = (2 * square()) / (sideA * sideB);
}


bool Triangle::isRectangular() const
{
	if ((sideA * sideA == sideB * sideB + sideC * sideC) || (sideB * sideB == sideC * sideC + sideA * sideA)
		|| (sideC * sideC == sideB * sideB + sideA * sideA))
		return true;
	return false;
}


void Triangle::operator+(const double increaseValue)
{
	increaseByConst(increaseValue);
}


void Triangle::operator*(const double increaseValue)
{
	sideA *= increaseValue;
	sideB *= increaseValue;
	sideC *= increaseValue;
}


double& Triangle::operator[](const int index)
{
	switch (index)
	{
	case 1:
		return sideA;
	case 2:
		return sideB;
	case 3:
		return sideC;
	default:
		break;
	}
}


const double& Triangle::operator[](const int index) const
{
	switch (index)
	{
	case 1:
		return sideA;
	case 2:
		return sideB;
	case 3:
		return sideC;
	default:
		break;
	}
}


Triangle::operator double() const
{
	return square();
}


bool operator <(const Triangle& leftTriangle, const Triangle& rightTriangle)
{
	return double(leftTriangle) < double(rightTriangle);
}


bool operator >(const Triangle& leftTriangle, const Triangle& rightTriangle)
{
	return double(leftTriangle) > double(rightTriangle);
}


bool operator==(const Triangle& leftTriangle, const Triangle& rightTriangle)
{
	return double(leftTriangle) == double(rightTriangle);
}


int Triangle::howMany()
{
	return howManyTriangles;
}