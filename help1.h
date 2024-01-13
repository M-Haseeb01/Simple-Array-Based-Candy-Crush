#include <Windows.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{
		whichKey = 5;		//5 if enter key is pressed
		return true;
	}
	return false;
}

void myRect(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}

void fullscreen()
{
	;
}


void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void cursorclear(int x1, int y1, int x2, int y2, int r, int g, int b) //CODE FOR CURSOR
{
	myLine(x1, y1, x1, y2, r, g, b);
	myLine(x1, y2, x2, y2, r, g, b);
	myLine(x1, y1, x2, y1, r, g, b);
	myLine(x2, y1, x2, y2, r, g, b);
}


void cursor(int x1, int y1, int x2, int y2, int r, int g, int b) //CODE FOR CURSOR
{
	myLine(x1, y1, x1, y2, r, g, b);
	myLine(x1, y2, x2, y2, r, g, b);
	myLine(x1, y1, x2, y1, r, g, b);
	myLine(x2, y1, x2, y2, r, g, b);
}



void octagon(int x1, int y1, int x2, int y2, int r, int b, int g)
{
	myLine(x1 + 20, y1, x2 - 20, y2 - 80, r, b, g);
	myLine(x1 + 60, y1, x2, y2 - 40, r, b, g);
	myLine(x1 + 80, y1 + 40, x2 - 20, y2, r, b, g);
	myLine(x1 + 60, y1 + 80, x2 - 60, y2, r, b, g);
	myLine(x1 + 20, y1 + 80, x2 - 80, y2 - 40, r, b, g);
	myLine(x1, y1 + 40, x2 - 60, y2 - 80, r, b, g);
}

void pyramid(int x1, int y1, int x2, int y2, int r, int g, int b)	//CODE FOR PYRAMID
{
	myLine(x1 + 40, y1, x2, y2 - 40, r, g, b);
	myLine(x1 + 40, y1, x2 - 80, y2 - 40, r, g, b);
	myLine(x1 + 40, y1 + 80, x2, y2 - 40, r, g, b);
	myLine(x1 + 40, y1 + 80, x2 - 80, y2 - 40, r, g, b);
}


void triangle(int x1, int y1, int x2, int y2, int r, int g, int b)	//CODE FOR TRIANGLE
{

	myLine(x1, y1, x2, y2, r, g, b);
	myLine(x1, y1, x1, y2, r, g, b);
	myLine(x1, y2, x2, y2, r, g, b);
}


void Grid()
{
	myRect(100, 100, 900, 900, 255, 255, 255);

	int y = 200;
	for (int i = 0; i < 7; i++)									//X-AXIS
	{
		myLine(100, y, 900, y, 255, 255, 255);
		y = y + 100;
	}

	int  x = 200;
	for (int i = 0; i < 7; i++)									//Y-AXIS
	{
		myLine(x, 100, x, 900, 255, 255, 255);
		x = x + 100;
	}
}


