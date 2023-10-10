#ifndef VECTORMATH_H

#define VECTORMATH_H

#include"Base.h"

class Point2D : ConsoleCoords
{
	
public:

#pragma region Ctor

	Point2D();
	
	Point2D(const UShort &x, const UShort &y);

	Point2D(const Point2D& other);
		
#pragma endregion

#pragma region Operators

#pragma region Math

	Point2D operator - (const Point2D& other);

	Point2D operator + (const Point2D& other);

#pragma endregion

	
#pragma region Casting

	//operator ConsoleCoords ();

#pragma endregion


#pragma endregion

		
};

/////////////////////////////////////////////////////

class Vector2D : ConsoleCoords
{
private:

	Point2D m_start;

	Point2D m_end;

public:
#pragma region Ctor

	Vector2D();
	
	Vector2D(Point2D &end, Point2D &start);

	Vector2D(Vector2D& other);

#pragma endregion

#pragma region Methods

#pragma region Getters and Setters
	
	Point2D GetStart() const;

	void SetStart(Point2D& start);

	Point2D GetEnd()const;

	void SetEnd(Point2D& end);

	void SetStartEnd(Point2D& start, Point2D& end);

#pragma endregion

	UShort GetLength() const;


#pragma endregion

};



#endif // !VECTORMATH_h

