To use his lib.
1) Put ConsoleLib.dll into some folder in your solution where it will be used.
2) Using runtime Loading to load DLL into your programm.

auto ConsoleLib = LoadLibrary(L"path to ConsoleLib.dll");

3) Create Pointers to functions of the DLL or use typedef. Just select what is more suitable for you.

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

4) Get functions from the library

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

5) Don't forget to clear library!.

FreeLibrary(ConsoleLib);