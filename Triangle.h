#pragma once
#include <cmath>
/* ТЗ
	На основі класу з попередньої лабораторної роботи:
	Перевантажити як мінімум три функції-члени з попереднього завдання.
	Перевантажити операції згідно з варіантом. Для операція, для яких не вказані символи, вибрати символи самостійно.
	Створити дружні функції згідно з варіантом.
	Створити статичні поля та статичні методи згідно з варіантом.
		Клас Triangle
		Як функції члени 
		1.Збільшення одразу всіх сторін трикутника на константу(+)
		2.Збільшення одразу всіх сторін трикутника у певну кількість разів(*)
		3.Доступ до і-ї сторони трикутника("[]")
		4. Приведення до дійсного типу(повертати його площу)
		Як дружні-функції
		Виведення трикутника з форми("<<")
		Виведення трикутника на форму(">>")
		Більше(">")
		Менше("<")
		Рівне("==")(при порівнянні порівнювати площі трикутників)
		Створити статичне поле, в якому б містилася інформація про кількість створенних об'єктів, а також статичні функції для роботи з цим полем.
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