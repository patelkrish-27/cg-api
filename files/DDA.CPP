#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    float x1 = 30, y1 = 20, x2 = 150, y2 = 60;
    float dx = x2 - x1, dy = y2 - y1;
    float m = dy / dx;
    float xi = x1, yi = y1;

    // Drawing line based on slope
    if (dx >= dy)
    {
        while (xi <= x2)
        {
            putpixel((int)xi, (int)yi, WHITE);
            xi += 1;
            yi += m;
        }
    }
    else
    {
        while (yi <= y2)
        {
            putpixel((int)xi, (int)yi, WHITE);
            yi += 1;
            xi += m;
        }
    }

    getch();
    closegraph();
    return 0;
}
