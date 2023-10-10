#include"VectorMath.h"
#include <cstddef>

#pragma region Point

#pragma region Definitions

#pragma region Ctors

Point2D::Point2D() :ConsoleCoords() {}

Point2D::Point2D(const Point2D& other)
{
	//Initialize private fields of the base class
	ConsoleCoords::SetXY(other.GetX(), other.GetY());

	//Init logic for the current class
}

Point2D::Point2D(const UShort x, const UShort y) : ConsoleCoords(x, y) {}



#pragma endregion

#pragma region Functions

#pragma region Getters

UShort Point2D::GetX() const
{
	return ConsoleCoords::GetX();
}

UShort Point2D::GetY() const
{
	return ConsoleCoords::GetY();
}

#pragma endregion

#pragma region Setters

void Point2D::SetX(UShort x)
{
	ConsoleCoords::SetX(x);
}

void Point2D::SetY(UShort y)
{
	ConsoleCoords::SetY(y);
}

void Point2D::SetXY(UShort x, UShort y)
{
	ConsoleCoords::SetXY(x, y);
}

#pragma endregion

#pragma endregion

#pragma region Operators

#pragma region Nath

Vector2D Point2D::operator-(const Point2D& start)const
{
	return Vector2D(start,*this);
}

#pragma endregion




#pragma endregion


#pragma endregion


#pragma endregion

#pragma region Vectors

#pragma region Ctors

Vector2D::Vector2D() : ConsoleCoords() 
{
	
}

Vector2D::Vector2D(const Point2D& start, const  Point2D& end)
{
	ReCalcVectorCoords(start, end);
}

Vector2D::Vector2D(const Vector2D& other)
{	
	SetXY(other.GetX(), other.GetY());
}

#pragma endregion

#pragma region Functions

#pragma region Private Functions



void Vector2D::ReCalcVectorCoords(const Point2D& start, const Point2D& end)
{
	ConsoleCoords::SetXY(end.GetX() - start.GetX(), end.GetY() - start.GetY());
}

#pragma endregion

#pragma region Getters

UShort Vector2D::GetX() const
{
	return ConsoleCoords::GetX();
}

UShort Vector2D::GetY() const
{
	return ConsoleCoords::GetY();
}

#pragma endregion

#pragma region Setters

void Vector2D::SetXY(UShort x, UShort y)
{
	ConsoleCoords::SetXY(x, y);
}

void Vector2D::SetX(UShort x)
{
ConsoleCoords:: SetX(x);
}

void Vector2D::SetY(UShort y)
{
	ConsoleCoords::SetY(y);
}

UShort Vector2D::GetLength()const
{
	return static_cast<UShort>(sqrtf(GetX() * GetX() + GetY() * GetY()));
}

#pragma endregion


#pragma endregion


#pragma endregion

