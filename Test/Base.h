#ifndef BASE_H

#define BASE_H

#include<iostream>
#include <string>

#pragma region Typedef

typedef unsigned short UShort;

#pragma endregion

//Base class for all types of objects that uses console coords system
class ConsoleCoords
{
private:
	//Private section of the class
	UShort m_x;//Position of the object with respect to X axis

	UShort m_y;//Position of thr object with respect to Y axis

	static unsigned char m_DIMENSIONS;

	static std::string m_InputMsg;

protected:
	/// <summary>
	/// Trys to parse string to number UShort
	/// </summary>
	static bool isNumber(const std::string& str, std::string& error, UShort &number);

public:
	

	//Public section of the class
#pragma region Ctor
	/// <summary>
	/// Empty ctor, inirializes ConsoleCoords object with 0 , 0 
	/// </summary>
	ConsoleCoords();

	/// <summary>
	/// Main ctor
	/// </summary>
	/// <param name="x">X coord</param>
	/// <param name="y">Y coord</param>
	ConsoleCoords(UShort x, UShort y);

	/// <summary>
	/// Copy ctor
	/// </summary>
	/// <param name="other">Object to copy values from</param>
	ConsoleCoords(const ConsoleCoords& other);

#pragma endregion

#pragma region Methods
	/// <summary>
	/// Gets the value of the X coord
	/// </summary>
	/// <returns>Object position according to X Axis</returns>
	virtual UShort GetX() const;

	/// <summary>
	/// Sets the X coord of the object 
	/// </summary>
	/// <param name="x">New x coord value</param>
	virtual void SetX(UShort x);

	/// <summary>
	/// Gets Y coord of the object
	/// </summary>
	/// <returns>Object position according to Y axis</returns>
	virtual UShort GetY() const;

	/// <summary>
	/// Set new Y coordinate value
	/// </summary>
	/// <param name="y">New y coord value</param>
	virtual void SetY(UShort y);

	/// <summary>
	/// Set new X and Y coordinate values
	/// </summary>
	/// <param name="x">New x coord value</param>
	/// <param name="y">New y coord value</param>
	virtual void SetXY(UShort x, UShort y);

#pragma endregion

#pragma region Operators
	/// <summary>
	/// Arithmetic assignment operator
	/// </summary>
	/// <param name="cc">ConsoleCoords Object</param>
	/// <returns>ref to current object</returns>
	ConsoleCoords &operator = (const ConsoleCoords& cc);

	friend std::istream& operator >> (std::istream& is, ConsoleCoords& c)
	{
		std::string str;
		std::string error;	

		UShort temp;

		for (int i = 1; i <= m_DIMENSIONS; ++i)
		{
			do
			{
				if (error.size() > 0)
					std::cout << error << std::endl;

				std::cout << m_InputMsg << ((i == 1)? "X" : "Y") << std::endl;

				is >> str;

			} while (!isNumber(str, error, temp));

			error.clear();

			i == 1 ? c.m_x = temp :
				c.m_y = temp;
		}
		
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, ConsoleCoords& c)
	{
		os << "X: " << c.m_x << std::endl << "Y: " << c.m_y << std::endl;

		return os;
	}

#pragma endregion

};

#endif // !BASE_H

