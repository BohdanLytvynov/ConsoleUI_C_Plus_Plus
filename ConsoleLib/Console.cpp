#include"pch.h"
#include"Console.h"


#pragma region Prototypes definition

#pragma region Initialization

bool ConsoleFuncs::Init(HANDLE console)
{
	if (console != NULL)
	{
		m_console = console;

		CONSOLE_SCREEN_BUFFER_INFO consoleBuf;

		if (GetConsoleScreenBufferInfo(m_console, &consoleBuf))
		{
			m_height = consoleBuf.srWindow.Bottom - consoleBuf.srWindow.Top + 1;

			m_width = consoleBuf.srWindow.Right - consoleBuf.srWindow.Left + 1;
		}
		return true;
	}

	return false;
}

#pragma endregion

#pragma region Console Size

const int& ConsoleFuncs::GetConsoleWidth()
{
	return m_width;
}

const int& ConsoleFuncs::GetConsoleHeight()
{
	return m_height;
}

#pragma endregion

#pragma region CursorPosition

short ConsoleFuncs::GetCursorPositionX() { return m_x; }

short ConsoleFuncs::GetCursorPositionY() { return m_y; }

void ConsoleFuncs::SetCursorPosition(short x, short y)
{
	m_x = x;

	m_y = y;

	SetConsoleCursorPosition(m_console, { x, y });
}

#pragma endregion

#pragma region Color maintainence

WORD* ConsoleFuncs::GetDefaultColor()
{
	return &m_DefaultColor;
}

void ConsoleFuncs::SetDefaultColor(WORD& color)
{
	if (color != NULL)
		m_DefaultColor = color;
}

#pragma endregion

#pragma region Print Functions

void ConsoleFuncs::PrintColoredSymbol(const char symb, WORD color)
{
	SetConsoleTextAttribute(m_console, color);

	PrintSymbol(symb);

	SetConsoleTextAttribute(m_console, m_DefaultColor);
}

void ConsoleFuncs::PrintSymbol(const char symb)
{	
	cout << symb << endl;
}

void ConsoleFuncs::PrintColorMsg(const string& msg, WORD color)
{
	SetConsoleTextAttribute(m_console, color);

	Print(msg);

	SetConsoleTextAttribute(m_console, m_DefaultColor);
}

void ConsoleFuncs::Print(const string& msg)
{
	cout << msg << endl;
}

void ConsoleFuncs::PrintAtCenter(const string& msg, short yoffset)
{
	SetCursorPosition(m_width / 2 - msg.size() / 2, yoffset);

	Print(msg);
}

void ConsoleFuncs::PrintColorMsgAtCenter(const string& msg, WORD color,
	short yoffset)
{
	SetCursorPosition(m_width / 2 - msg.size() / 2, yoffset);

	PrintColorMsg(msg, color);
}

#pragma endregion

#pragma region Input Functions

double ConsoleFuncs::InputNumber(const string& msg, WORD color,
	bool (*InputCheck) (const string&))
{
	string temp;

	for (; ;)
	{
		PrintColorMsg(msg, color);

		cin >> temp;

		if (InputCheck == NULL)
			break;
		else if (InputCheck(temp))
			break;
		else
			continue;
	}

	return stod(temp);

}

string ConsoleFuncs::Input(const string& msg, WORD color,
	bool (*InputCheck) (const string&))
{
	string temp;

	for (; ;)
	{
		PrintColorMsg(msg, color);

		getline(cin, temp);

		if (InputCheck == NULL)
			break;
		else if (InputCheck(temp))
			break;
		else
			continue;
	}

	return temp;
}

char ConsoleFuncs::InputKey(const string& msg, WORD color)
{
	PrintColorMsg(msg, color);

	return _getch();
}

#pragma endregion

#pragma region Console Graphics

void ConsoleGraphics::DrawRect(const unsigned short x,
	const unsigned short y,
	const unsigned short width,
	const unsigned short height,	
	WORD BorderColor, WORD Fill)
{
	ConsoleFuncs::SetCursorPosition(x, y);
	
	short tempX = x;

	short tempY = y;
	
	//Right upper corner

	short rightUpperX = x + width-2;
		
	short rightLowerY = y + std::ceil(height/2) - 3;

#pragma region Draw Border

	ConsoleFuncs::SetCursorPosition(tempX, tempY);

	ConsoleFuncs::PrintColoredSymbol(char(201), BorderColor);
	
	while (tempX< rightUpperX)
	{
		tempX++;

		ConsoleFuncs::SetCursorPosition(tempX, tempY);

		ConsoleFuncs::PrintColoredSymbol(char(205), BorderColor);
	}
	
	tempX++;

	ConsoleFuncs::SetCursorPosition(tempX, tempY);

	ConsoleFuncs::PrintColoredSymbol(char(187), BorderColor);

	while (tempY <= rightLowerY)
	{
		tempY++;

		ConsoleFuncs::SetCursorPosition(tempX, tempY);
		
		ConsoleFuncs::PrintColoredSymbol(char(186), BorderColor);
	}

	tempY++;

	ConsoleFuncs::SetCursorPosition(tempX, tempY);

	ConsoleFuncs::PrintColoredSymbol(char(188), BorderColor);

	while (tempX > x+1)
	{
		tempX--;

		ConsoleFuncs::SetCursorPosition(tempX, tempY);

		ConsoleFuncs::PrintColoredSymbol(char(205), BorderColor);
	}

	tempX--;

	ConsoleFuncs::SetCursorPosition(tempX, tempY);

	ConsoleFuncs::PrintColoredSymbol(char(200), BorderColor);

	while (tempY > y+1)
	{
		tempY--;

		ConsoleFuncs::SetCursorPosition(tempX, tempY);

		ConsoleFuncs::PrintColoredSymbol(char(186), BorderColor);
	}

#pragma endregion

#pragma region Fill

	tempX++;

	short ret = tempX;

	for (; tempY < rightLowerY+2; tempY++)
	{
		for ( ; tempX < (x + width - 1); tempX++ )
		{
			ConsoleFuncs::SetCursorPosition(tempX, tempY);

			ConsoleFuncs::PrintColorMsg(" ", Fill);
		}

		tempX = ret;
	}

#pragma endregion


	ConsoleFuncs::SetCursorPosition(0, rightLowerY + 1);
}

void ConsoleGraphics::DrawTextBlock(const unsigned short x, const unsigned short y,
	const unsigned short width,
	const unsigned short height,	
	WORD BorderColor, WORD Fill, const string& text, 
	WORD Foreground, vector<unsigned short> relTxtPos, bool Wrapping)
{
	if (relTxtPos.size() > 2)
		throw runtime_error("Error! There can be only 2 dimensions!!!");

	short textBlockWidth;

	short textBlockHeight;

	auto YpaddingUp = std::ceil(relTxtPos[1] / 2);

	short wrappingCount;
		
	if (Wrapping)
	{
		textBlockWidth = width + relTxtPos[0] * 2;

		wrappingCount = std::ceil(text.size() / (textBlockWidth));

		textBlockHeight = wrappingCount + height + YpaddingUp;
	}
	else
	{
		textBlockWidth = (unsigned short)text.size() + relTxtPos[0] * 2;

		textBlockHeight = height;
	}
	
	ConsoleGraphics::DrawRect(x, y, textBlockWidth, textBlockHeight,
		BorderColor, Fill);

	auto txtLeftX = x + relTxtPos[0];

	auto txtLeftY = y + YpaddingUp;

	auto InitLeftX = txtLeftX;

	if (Wrapping)
	{
		for (int i = 0; i < text.size(); i++)
		{
			ConsoleFuncs::SetCursorPosition(txtLeftX, txtLeftY);

			ConsoleFuncs::PrintColoredSymbol(text[i], Foreground);

			txtLeftX++;

			if (txtLeftX >= InitLeftX + width)
			{
				txtLeftY++;

				txtLeftX = InitLeftX;
			}
		}
	}
	else
	{				
		ConsoleFuncs::SetCursorPosition(txtLeftX, txtLeftY);

		ConsoleFuncs::PrintColorMsg(text, Foreground);
	}	
}

#pragma endregion


	HANDLE* ConsoleFuncs::GetHandle()
{
	if (m_console != NULL)
		return &m_console;

	return nullptr;
}

#pragma endregion
