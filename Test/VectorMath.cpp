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

Point2D::Point2D(UShort x, UShort y) : ConsoleCoords(x, y) {}

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



#pragma endregion




#pragma endregion


#pragma endregion


#pragma endregion

#pragma region Vectors

#pragma region Ctors

Vector2D::Vector2D() : ConsoleCoords() 
{
	m_start = Point2D(0,0);

	m_end = Point2D(0, 0);
}

Vector2D::Vector2D(Point2D& start, Point2D& end) :  m_start(start), m_end(end)
{
	ReCalcVectorCoords(start, end);
}

Vector2D::Vector2D(const Vector2D& other)
{
	m_start = other.GetStart();

	m_end = other.GetEnd();

	SetXY(other.GetX(), other.GetY());
}

#pragma endregion

#pragma region Functions

#pragma region Private Functions

void Vector2D::SetXY(UShort x, UShort y)
{
	ConsoleCoords::SetXY(x, y);
}

void Vector2D::ReCalcVectorCoords(const Point2D& start, const Point2D& end)
{
	ConsoleCoords::SetXY(end.GetX() - start.GetX(), end.GetY() - start.GetY());
}

#pragma endregion

#pragma region Getters

Point2D Vector2D::GetStart() const
{
	return m_start;
}

Point2D Vector2D::GetEnd() const
{
	return m_end;
}

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

void Vector2D::SetStart(Point2D start)
{
	m_start = start;

	ReCalcVectorCoords(m_start, m_end);
}

void Vector2D::SetEnd(Point2D end)
{
	m_end - end;

	ReCalcVectorCoords(m_start, m_end);
}


void Vector2D::SetStartEnd(Point2D start, Point2D end)
{
	m_start = start;

	m_end = end;

	ReCalcVectorCoords(m_start, m_end);
}

#pragma endregion


#pragma endregion


#pragma endregion

