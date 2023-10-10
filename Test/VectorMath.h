#ifndef VECTORMATH_H

#define VECTORMATH_H

#include"Base.h"
//Derivate form ConsoleCoords base class
class Point2D : public ConsoleCoords
{
	
public:
	//Public section
#pragma region Ctor
	/// <summary>
	/// Empty ctor
	/// </summary>
	Point2D();
	
	/// <summary>
	/// Initialize new point with x and y coords
	/// </summary>
	/// <param name="x">X coord</param>
	/// <param name="y">Y coord</param>
	Point2D(UShort x, UShort y);

	/// <summary>
	/// Copy ctor
	/// </summary>
	/// <param name="other"></param>
	Point2D(const Point2D& other);
		
#pragma endregion

#pragma region Getters

	/// <summary>
	/// Get X coordinate of the point
	/// </summary>
	/// <returns>X coord</returns>
	UShort GetX() const;

	/// <summary>
	/// Get Y coordinate of the point
	/// </summary>
	/// <returns>Y coord</returns>
	UShort GetY() const;

#pragma endregion

#pragma region Setters
	/// <summary>
	/// Set X coordinate
	/// </summary>
	/// <param name="x">New x coord</param>
	void SetX(UShort x);

	/// <summary>
	/// Set Y coordinate
	/// </summary>
	/// <param name="y">New y coord</param>
	void SetY(UShort y);

	/// <summary>
	/// Set X and Y coordinate
	/// </summary>
	/// <param name="x">New X</param>
	/// <param name="y">New Y</param>
	void SetXY(UShort x, UShort y);

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
//This class derivates from ConsoleCoords base. It adds X and Y Coordinate of the Vector
class Vector2D : public ConsoleCoords
{
private:
	
	//Start point
	Point2D m_start;

	//End point
	Point2D m_end;

	void ReCalcVectorCoords(const Point2D &start, const Point2D &end);

	void SetXY(UShort x, UShort y);

public:
#pragma region Ctor

	/// <summary>
	/// Empty standart ctro
	/// </summary>
	Vector2D();
	
	/// <summary>
	/// Main ctor
	/// </summary>
	/// <param name="start">Start Point</param>
	/// <param name="end">End Point</param>
	Vector2D(Point2D &start, Point2D& end);

	/// <summary>
	/// Copy Ctor
	/// </summary>
	/// <param name="other">ref to Object source</param>
	Vector2D(const Vector2D& other);

#pragma endregion

#pragma region Methods

#pragma region Getters
	/// <summary>
	/// Get Start point of the vector
	/// </summary>
	/// <returns>Start point</returns>
	Point2D GetStart() const;
	
	/// <summary>
	/// Get the endpoint of the vector
	/// </summary>
	/// <returns>End point</returns>
	Point2D GetEnd()const;

	/// <summary>
	/// Gets the X coord of the Vector
	/// </summary>
	/// <returns>X coord</returns>
	UShort GetX() const;

	/// <summary>
	/// Gets Y coord of the vector
	/// </summary>
	/// <returns>Y coord</returns>
	UShort GetY() const;

#pragma endregion

#pragma region Setters

	/// <summary>
	/// Sets new start point, recalculate vector coords
	/// </summary>
	/// <param name="start"></param>
	void SetStart(Point2D start);

	/// <summary>
	/// Sets new end point, recalculates vector coords
	/// </summary>
	/// <param name="end"></param>
	void SetEnd(Point2D end);

	/// <summary>
	/// Sets new start and end ppoints, recalculate vector coords
	/// </summary>
	/// <param name="start"></param>
	/// <param name="end"></param>
	void SetStartEnd(Point2D start, Point2D end);

#pragma endregion

UShort GetLength() const;


#pragma endregion

};



#endif // !VECTORMATH_h

