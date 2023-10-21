// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string>
#include<vector>
#include"VectorMath.h"

using namespace VectorMath;

using namespace std;
#pragma region Func Pointers

#pragma region Initialization

bool (*Init) (HANDLE);

#pragma endregion

#pragma region Console Size

const int& (*GetConsoleWidth)();

const int& (*GetConsoleHeight)();

#pragma endregion

#pragma region ConsoleCursor

 short (*GetCursorPositionX)();

 short (*GetCursorPositionY)();

 void (*SetCursorPosition)(short x, short y);

#pragma endregion

#pragma region Console Color

void (*SetDefColor) (WORD&);

WORD* (*GetDefColor) (void);

#pragma endregion

#pragma region Print
void (*Print) (const string&);

void (*PrintColorMessage) (const string&, WORD);

void (*PrintAtCenter)(const string & msg, short yoffset);

void (*PrintColorMsgAtCenter)(const string & msg, WORD color, short yoffset);

#pragma endregion

#pragma region Input

HANDLE* (*GetHandle)(void);

string(*Input) (const string&, WORD, bool (*) (const string&));

char (*InputKey) (const string&, WORD);

#pragma endregion

#pragma region Console Graphics

void (*DrawRect)(int x, int y, int width,
    int height,
    WORD BorderColor, WORD Fill);

void (*DrawTextBlock)(const unsigned short x, const unsigned short y,
    const unsigned short width,
    const unsigned short height,
    WORD BorderColor, WORD Fill, const string& text,
    WORD Foreground, vector<unsigned short> padding, bool Wrapping);

#pragma endregion


#pragma endregion

#pragma region CheckFunctions

bool ValString(const string& str)
{
    for (char c : str)
    {
        if (islower(c))
        {
            PrintColorMessage("Error", FOREGROUND_RED);

            return false;
        }
            
    }

    return true;
}

#pragma endregion


int main()
{
    WORD white = FOREGROUND_RED | FOREGROUND_GREEN |
        FOREGROUND_BLUE | FOREGROUND_INTENSITY;

#pragma region Get Lib Functions

    auto ConsoleLib = LoadLibrary(L"../x64/Debug/ConsoleLib.dll");

    DrawTextBlock = (decltype(DrawTextBlock))GetProcAddress(ConsoleLib, "DrawTextBlock");

    DrawRect = (decltype(DrawRect))GetProcAddress(ConsoleLib, "DrawRect");

    PrintAtCenter = (decltype(PrintAtCenter))GetProcAddress(ConsoleLib, "PrintAtCenter");

    PrintColorMsgAtCenter = (decltype(PrintColorMsgAtCenter))GetProcAddress(ConsoleLib, "PrintColorMsgAtCenter");

    GetCursorPositionX = (decltype(GetCursorPositionX))GetProcAddress(ConsoleLib, "GetCursorPositionX");

    GetCursorPositionY = (decltype(GetCursorPositionY))GetProcAddress(ConsoleLib, "GetCursorPositionY");

    SetCursorPosition = (decltype(SetCursorPosition))GetProcAddress(ConsoleLib, "SetCursorPosition");

    GetConsoleWidth = (decltype(GetConsoleWidth))GetProcAddress(ConsoleLib, "GetConsoleWidth");

    GetConsoleHeight = (decltype(GetConsoleHeight))GetProcAddress(ConsoleLib, "GetConsoleHeight");

    Init = (bool (*) (HANDLE))GetProcAddress(ConsoleLib, "Init");

    SetDefColor = (decltype(SetDefColor))GetProcAddress(ConsoleLib, "SetDefaultColor");

    GetDefColor = (decltype(GetDefColor))GetProcAddress(ConsoleLib, "GetDefaultColor");

    Print = (void (*) (const string&))GetProcAddress(ConsoleLib, "Print");

    PrintColorMessage = (decltype(PrintColorMessage))GetProcAddress(ConsoleLib, "PrintColorMsg");

    GetHandle = (decltype(GetHandle))GetProcAddress(ConsoleLib, "GetHandle");

    Input = (decltype(Input))GetProcAddress(ConsoleLib, "Input");

    InputKey = (decltype(InputKey))GetProcAddress(ConsoleLib, "InputKey");

#pragma endregion
    
    if (Init(GetStdHandle(STD_OUTPUT_HANDLE)))
    {
        SetDefColor(white);

        auto def = *GetDefColor();

        auto width = GetConsoleWidth();

        auto height = GetConsoleHeight();

        string header = "Drawing the rectangle";
   
        PrintColorMsgAtCenter(header, FOREGROUND_RED | FOREGROUND_GREEN, 0);

        /*DrawRect(2,2, 14,14, 
            (BACKGROUND_RED | BACKGROUND_GREEN) |
            (FOREGROUND_BLUE),
            BACKGROUND_BLUE
            );*/
           
        /*vector<unsigned short> relTxtPos = {5,10};

        DrawTextBlock(10, 5, 20,20, (BACKGROUND_RED | BACKGROUND_GREEN) |
            (FOREGROUND_BLUE),
            BACKGROUND_BLUE, "Some frase for testing Some frase for testing Some frase for testing",
            0 | (FOREGROUND_RED | FOREGROUND_GREEN |
                FOREGROUND_BLUE | FOREGROUND_INTENSITY), 
            relTxtPos, true);*/


        Point2D p1(3, 3);

        Point2D p2(1,1);

        Point2D p3(4, 4);

        Point2D p4(1, 1);
        
        Vector2D v1 = p1 - p2;

        Vector2D v2 = p3 - p4;

        Vector2D increment(1, 1);

        Vector2D v5(6,6);

        cout << v1;

        cout << v2;

        cout << "DotProduct: " << v1.DotProduct(v2) << " Operator *: " << v1 * v2 << endl;

        cout << "Vector Length: " << v1.GetLength() << endl;

        Vector2D vres = v1 + v2;

        cout << "v1 + v2: " << vres << endl;

        vres = v2 - v1;

        cout << "v2 - v1: " << vres << endl;

        cout << v5;

        v5 += increment;

        cout << "V5 += increment: " << v5 << endl;

        v5 -= increment;

        cout << "V5 -= increment: " << v5 << endl;

        system("Pause");

        SetCursorPosition(0, 15);
    }    

    FreeLibrary(ConsoleLib);
}


