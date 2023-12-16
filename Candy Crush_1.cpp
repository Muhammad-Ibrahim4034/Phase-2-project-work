#include<iostream>
#include <queue>
#include<time.h>
#include <windows.h>

using namespace std;

void printTime(int& starttime, int& score)
{
	if (time(0) - starttime <= 1000)
		cout << "Time = " << time(0) - starttime << " Score =  " << score << "\n";
}


void myLine(int x1, int y1, int x2, int y2, int R, int G, int B, int width) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, width, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}



void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

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
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}




void SelectionRectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	//This function prints the selection rectangle at the specified coordinates
	int width = 5;
	myLine(x1, y1, x2, y1, R, G, B, width);
	myLine(x1, y1, x1, y2, R, G, B, width);
	myLine(x1, y2, x2, y2, R, G, B, width);
	myLine(x2, y1, x2, y2, R, G, B, width);
}

void background()
{

	//Background
	myRectangle(0, 0, 1920, 1080, 0, 255, 255);
	myRectangle(540, 0, 1000, 600, 102, 51, 0);
	myRectangle(560, 10, 945, 50, 51, 20, 0);
	myRectangle(0, 400, 540, 600, 255, 255, 0);
	//This code is used to print the character
	{
		//cape
		myEllipse(420, 120, 440, 320, 255, 0, 0);
		myEllipse(330, 120, 350, 320, 255, 0, 0);
		myEllipse(335, 180, 433, 340, 0, 0, 255);
		//lower belly
		myEllipse(345, 180, 425, 290, 20, 56, 160);
		//Waist
		myRectangle(340, 120, 430, 220, 240, 0, 0);
		//Belt
		myEllipse(345, 210, 425, 290, 20, 56, 160);
		//cape
		myEllipse(300, 270, 480, 420, 0, 255, 255);
		myLine(345, 120, 338, 240, 0, 0, 255, 3);
		myLine(418, 120, 425, 240, 0, 0, 255, 5);
		myEllipse(418, 120, 435, 150, 0, 0, 255);
		//corlar
		myLine(405, 127, 380, 150, 240, 240, 240, 20);
		myLine(355, 130, 380, 150, 240, 240, 240, 20);
		myLine(353, 125, 408, 125, 240, 240, 240, 15);
		//head
		myEllipse(360, 90, 400, 120, 255, 206, 180);
		myEllipse(365, 20, 410, 120, 255, 206, 180);
		myEllipse(360, 20, 420, 40, 240, 160, 0);
		myEllipse(355, 30, 380, 40, 240, 160, 0);
		myEllipse(390, 110, 380, 100, 255, 164, 0);
		myEllipse(385, 107, 370, 103, 255, 164, 0);
		myLine(375, 103, 370, 107, 255, 164, 0, 6);
		myLine(369, 102, 360, 105, 255, 164, 0, 8);
		myEllipse(390, 50, 395, 60, 60, 60, 60);
		myEllipse(375, 50, 380, 60, 60, 60, 60);
		myLine(390, 45, 400, 45, 240, 160, 0, 4);
		myLine(372, 45, 380, 45, 240, 160, 0, 4);
		//Smile
		myLine(373, 82, 377, 85, 0, 0, 0, 2);
		myLine(377, 85, 382, 87, 0, 0, 0, 2);
		myLine(382, 87, 390, 80, 0, 0, 0, 2);
		//tie
		myLine(382, 123, 380, 158, 20, 56, 120, 12);
		myLine(375, 121, 380, 130, 20, 56, 120, 10);
		myLine(390, 121, 380, 130, 20, 56, 120, 10);
		myLine(375, 121, 390, 121, 20, 56, 120, 10);
		//pattern
		myLine(346, 135, 342, 219, 255, 214, 20, 3);
		myLine(360, 147, 361, 215, 255, 214, 20, 3);
		myLine(395, 150, 394, 210, 255, 214, 20, 3);
		myLine(414, 133, 417, 220, 255, 214, 20, 3);
		myEllipse(372, 205, 392, 225, 255, 215, 0);
		//arm left
		myLine(335, 130, 300, 205, 255, 0, 0, 20);
		myLine(300, 205, 260, 150, 255, 0, 0, 20);
		myLine(250, 147, 270, 148, 0, 0, 255, 20);
		myLine(240, 130, 270, 131, 220, 220, 220, 20);
		myLine(223, 127, 272, 200, 0, 255, 255, 18);
		myLine(270, 125, 290, 160, 0, 255, 255, 18);
		myEllipse(327, 124, 343, 140, 255, 215, 0);
		myEllipse(290, 188, 310, 210, 255, 215, 0);
		myLine(335, 143, 315, 188, 255, 214, 20, 2);
		myLine(323, 143, 305, 182, 255, 214, 20, 2);
		myLine(265, 163, 284, 192, 255, 214, 20, 2);
		//hand left
		myEllipse(223, 80, 270, 125, 236, 188, 180);
		myLine(225, 79, 270, 79, 0, 255, 255, 25);
		myEllipse(245, 80, 280, 110, 0, 255, 255);
		myEllipse(250, 95, 270, 120, 230, 190, 180);
		myLine(230, 93, 228, 105, 0, 255, 255, 2);
		myLine(235, 93, 237, 107, 0, 255, 255, 2);
		//arm right
		myLine(435, 132, 470, 190, 255, 0, 0, 20);
		myLine(470, 190, 460, 290, 255, 0, 0, 20);
		myLine(455, 293, 467, 298, 0, 0, 255, 20);
		myLine(450, 308, 470, 315, 220, 220, 220, 20);
		myLine(444, 288, 440, 315, 0, 255, 255, 13);
		myLine(478, 288, 474, 320, 0, 255, 255, 15);
		myEllipse(428, 125, 445, 143, 255, 215, 0);
		myEllipse(460, 180, 480, 200, 255, 215, 0);
		myLine(437, 145, 459, 179, 255, 214, 20, 2);
		myLine(448, 145, 465, 170, 255, 214, 20, 2);
		myLine(468, 205, 459, 280, 255, 214, 20, 2);
		//hand right
		myEllipse(440, 320, 480, 370, 236, 188, 180);
		myLine(450, 327, 445, 360, 0, 255, 255, 15);
		myEllipse(435, 320, 465, 350, 230, 190, 180);
		myLine(463, 370, 465, 355, 0, 255, 255, 2);
		//legs
		myRectangle(355, 270, 385, 420, 20, 56, 160);
		myRectangle(390, 270, 420, 420, 20, 56, 160);
		myEllipse(350, 275, 365, 400, 0, 255, 255);
		myEllipse(408, 275, 430, 400, 0, 255, 255);
		myEllipse(365, 325, 385, 345, 255, 215, 0);
		myEllipse(389, 325, 409, 345, 255, 215, 0);
		//feet
		myEllipse(325, 400, 385, 430, 30, 30, 30);
		myEllipse(387, 400, 447, 430, 30, 30, 30);

	}
}