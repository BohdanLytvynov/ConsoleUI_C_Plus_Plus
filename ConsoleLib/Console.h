#ifndef CONSOLE_H

#define CONSOLE_H

#pragma region DLL Export Import Specification

#ifdef CONSOLE_EXPORTS

#define DLL_SPEC __declspec(dllexport)

#else 

#define DLL_SPEC __declspec(dllimport)

#endif // CONSOLE_EXPORTS

#pragma endregion

#include <windows.h>
#include<iostream>
#include <string>
#include <conio.h>
#include<math.h>
#include<vector>

using namespace std;

namespace ConsoleFuncs
{
#pragma region Dll internal state

	extern WORD m_DefaultColor;

	extern HANDLE m_console;

	extern short m_x;

	extern short m_y;

	extern int m_height;

	extern int m_width;

#pragma endregion

#pragma region Prototypes declaretion

#pragma region Console Size

	extern "C" DLL_SPEC const int& GetConsoleWidth();

	extern "C" DLL_SPEC const int& GetConsoleHeight();

#pragma endregion


#pragma region Cursor Position

	extern "C" DLL_SPEC short GetCursorPositionX();

	extern "C" DLL_SPEC short GetCursorPositionY();

	extern "C" DLL_SPEC void SetCursorPosition(short x, short y);

#pragma endregion

#pragma region Print Functions

	extern "C" DLL_SPEC void Print(const string & msg);

	extern "C" DLL_SPEC void PrintColorMsg(const string & msg, WORD color);

	extern "C" DLL_SPEC void PrintAtCenter(const string & msg, short yoffset);

	extern "C" DLL_SPEC void PrintColorMsgAtCenter(const string & msg, WORD color, short yoffset);

	extern "C" DLL_SPEC void PrintSymbol(const char symb);

	extern "C" DLL_SPEC void PrintColoredSymbol(const char symb, WORD color);

#pragma endregion

#pragma region InputFunctions

	extern "C" DLL_SPEC double InputNumber(const string & msg, WORD color,
		bool (*InputCheck) (const string&));

	extern "C" DLL_SPEC string Input(const string & msg, WORD color,
		bool (*InputCheck) (const string&));

	extern "C" DLL_SPEC char InputKey(const string & msg, WORD color);

#pragma endregion

#pragma region Color maintainence functions
	extern "C" DLL_SPEC void SetDefaultColor(WORD & color);

	extern "C" DLL_SPEC WORD * GetDefaultColor();
#pragma endregion
		
	extern "C" DLL_SPEC bool Init(HANDLE console);

	extern "C" DLL_SPEC HANDLE* GetHandle();
		
#pragma endregion

}

namespace ConsoleGraphics
{
	extern "C" DLL_SPEC void DrawRect(const unsigned short x, const unsigned short y,
		const unsigned short width,
		const unsigned short height, 		
		WORD BorderColor, WORD Fill);

	extern "C" DLL_SPEC void DrawTextBlock(const unsigned short x, const unsigned short y,
		const unsigned short width,
		const unsigned short height,
		WORD BorderColor, WORD Fill, const string & text,
		WORD Foreground, vector<unsigned short> relTxtPos, bool Wrapping);
}






#endif // !CONSOLE_H

