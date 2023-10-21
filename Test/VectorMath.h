#ifndef VECTORMATH_H

#define VECTORMATH_H

#include"Base.h"
#include<cmath>
#include<iostream>

namespace VectorMath
{
	class Vector2D;

	//Derivate form ConsoleCoords base class
	class Point2D : private ConsoleCoords
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
		Point2D(const UShort x, const UShort y);

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

		Vector2D operator - (const Point2D& other)const;

		Point2D operator + (const Point2D& other);

#pragma endregion

#pragma region Input Output

		friend std::istream& operator >> (std::istream& is, Point2D& p)
		{
			ConsoleCoords c;

			is >> c;

			p.SetXY(c.GetX(), c.GetY());

			return is;
		}

		friend std::ostream& operator << (std::ostream& os, Point2D& p)
		{
			os << "X: " << p.GetX() << std::endl << "Y: " << p.GetY() << std::endl;

			return os;
		}

#pragma endregion

#pragma endregion


	};

	/////////////////////////////////////////////////////
	//This class derivates from ConsoleCoords base. It adds X and Y Coordinate of the Vector
	class Vector2D : private ConsoleCoords
	{
	private:

		void ReCalcVectorCoords(const Point2D& start, const Point2D& end);

	public:
#pragma region Ctor

		/// <summary>
		/// Empty standart ctor
		/// </summary>
		Vector2D();

		/// <summary>
		/// Main ctor
		/// </summary>
		/// <param name="start">Start Point</param>
		/// <param name="end">End Point</param>
		Vector2D(const Point2D& start, const Point2D& end);

		/// <summary>
		/// Copy Ctor
		/// </summary>
		/// <param name="other">ref to Object source</param>
		Vector2D(const Vector2D& other);

		Vector2D(const UShort x, const UShort y);

#pragma endregion

#pragma region Methods

#pragma region Getters


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
		/// Set X and Y coord of the Vector
		/// </summary>
		/// <param name="x">New X coord</param>
		/// <param name="y">New Y coord</param>
		void SetXY(UShort x, UShort y);

		/// <summary>
		/// Set X coord of the Vector
		/// </summary>
		/// <param name="x">new X coord</param>
		void SetX(UShort x);

		/// <summary>
		/// Set Y coord of the Vector
		/// </summary>
		/// <param name="y">New Y coord</param>
		void SetY(UShort y);

#pragma endregion
		/// <summary>
		/// Get Vector Length
		/// </summary>
		/// <returns></returns>
		UShort GetLength() const;

		Vector2D Normalize();

		UShort DotProduct(const Vector2D& vector)const;



#pragma region Operators

		Vector2D operator + (const Vector2D& vector)const;

		Vector2D operator - (const Vector2D& vector)const;

		UShort operator * (const Vector2D& vector)const;

		Vector2D operator * (const UShort& number)const;

		Vector2D& operator = (const Vector2D& vector);

		void operator += (const Vector2D& other);

		void operator -= (const Vector2D& other);
		
		void operator *= (const UShort& number);

		UShort operator [] (const unsigned int& i) const;

#pragma region Logical Operations
		bool operator == (const Vector2D& other)const;

		bool operator != (const Vector2D& other)const;

		bool operator > (const Vector2D& other)const;

		bool operator < (const Vector2D& other)const;

		bool operator >= (const Vector2D& other)const;

		bool operator <= (const Vector2D& other)const;
#pragma endregion


#pragma region Input OutPut
	
		friend std::ostream& operator << (std::ostream& os, Vector2D &vector)
		{
			os << "Vector X: " << vector.GetX() << std::endl << "Vector Y: " << vector.GetY() << std::endl;

			return os;
		}

#pragma endregion


#pragma endregion


#pragma endregion

	};
}


#endif // !VECTORMATH_h

