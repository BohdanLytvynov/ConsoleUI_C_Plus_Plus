#include"VectorMath.h"
#include <cstddef>

#pragma region Point

#pragma region Definitions

#pragma region Ctors

Point2D::Point2D() :ConsoleCoords() {}

Point2D::Point2D(const Point2D& other) : ConsoleCoords(other) {}

Point2D::Point2D(const UShort &x, const UShort &y) : ConsoleCoords(x, y) {}

#pragma endregion

#pragma region Functions


#pragma endregion

#pragma region Operators

#pragma region Nath

Point2D operator - (const Point2D& other)
{
	return Point2D();

}

#pragma endregion


//Point2D::operator ConsoleCoords()
//{
//	return ConsoleCoords(m_x, m_y);
//}

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

Vector2D::Vector2D(Point2D& end, Point2D& start) : m_end(end), m_start(start)
{
	
}

#pragma endregion


#pragma endregion

