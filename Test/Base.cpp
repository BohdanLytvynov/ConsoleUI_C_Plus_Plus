#include"Base.h"

#pragma region Definition of the functions

#pragma region Ctors

ConsoleCoords::ConsoleCoords() : m_x(0), m_y(0) {}

ConsoleCoords::ConsoleCoords(UShort x, UShort y) : m_x(x), m_y(y) {}

ConsoleCoords::ConsoleCoords(ConsoleCoords& other) : m_x(other.m_x), m_y(other.m_y) {}

#pragma endregion

#pragma region Functions

#pragma region Get Set X

UShort ConsoleCoords::GetX() const
{
	return m_x;
}

void ConsoleCoords::SetX(UShort x)
{
	m_x = x;
}

#pragma endregion

#pragma region Get Set Y

UShort ConsoleCoords::GetY() const
{
	return m_y;
}

void ConsoleCoords::SetY(UShort y)
{
	m_y = y;
}

void ConsoleCoords::SetXY(UShort x, UShort y)
{
	m_x = x;

	m_y = y;
}

#pragma endregion

#pragma endregion

#pragma region Operators

ConsoleCoords& ConsoleCoords::operator= (const ConsoleCoords& other)
{
	m_x = other.m_x;

	m_y = other.m_y;

	return *this;
}

#pragma endregion


#pragma endregion
