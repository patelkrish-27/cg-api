#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// Constants for region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;	  // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;	  // 1000

// Function to calculate the region code of a point
int regionCode(float x, float y, float xmin, float xmax, float ymin, float ymax)
{
	int code = INSIDE;

	if (x < xmin)
		code |= LEFT;
	if (x > xmax)
		code |= RIGHT;
	if (y < ymin)
		code |= BOTTOM;
	if (y > ymax)
		code |= TOP;

	return code;
}

// Function to calculate the intersection point
void calculateIntersection(float x1, float y1, float m, int regionCode, float xmin, float xmax, float ymin, float ymax, float *ix, float *iy)
{
	if (regionCode & TOP)
	{
		*ix = x1 + (ymax - y1) / m;
		*iy = ymax;
	}
	else if (regionCode & BOTTOM)
	{
		*ix = x1 + (ymin - y1) / m;
		*iy = ymin;
	}
	else if (regionCode & RIGHT)
	{
		*iy = y1 + m * (xmax - x1);
		*ix = xmax;
	}
	else if (regionCode & LEFT)
	{
		*iy = y1 + m * (xmin - x1);
		*ix = xmin;
	}
}

int main()
{
	int gd = DETECT, gm;
	float p1x = 10, p1y = 30, p2x = 80, p2y = 90;
	float xmin = 20, ymin = 20, xmax = 90, ymax = 70;
	float m = (p2y - p1y) / (p2x - p1x);
	float currentx1 = p1x, currentx2 = p2x, currenty1 = p1y, currenty2 = p2y;

	int p1rc = regionCode(p1x, p1y, xmin, xmax, ymin, ymax);
	int p2rc = regionCode(p2x, p2y, xmin, xmax, ymin, ymax);

	if (p1rc != INSIDE)
	{
		calculateIntersection(p1x, p1y, m, p1rc, xmin, xmax, ymin, ymax, &currentx1, &currenty1);
	}

	if (p2rc != INSIDE)
	{
		calculateIntersection(p2x, p2y, m, p2rc, xmin, xmax, ymin, ymax, &currentx2, &currenty2);
	}

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(10, 5, "Before Clipping");
	rectangle((int)xmin, (int)ymin, (int)xmax, (int)ymax);
	line((int)p1x, (int)p1y, (int)p2x, (int)p2y);

	outtextxy(160, 5, "After Clipping");
	rectangle((int)xmin + 150, (int)ymin, (int)xmax + 150, (int)ymax);
	line((int)currentx1 + 150, (int)currenty1, (int)currentx2 + 150, (int)currenty2);

	getch();
	closegraph();
	return 0;
}
