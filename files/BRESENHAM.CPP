#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    int x1 = 10, y1 = 10, x2 = 50, y2 = 30;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int xi = x1, yi = y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    if (dx >= dy)
    {
        for (xi = x1; xi <= x2; xi++)
        {
            putpixel(xi, yi, WHITE);
            if (p >= 0)
            {
                yi++;
                p += 2 * (dy - dx);
            }
            else
            {
                p += 2 * dy;
            }
        }
    }
    else
    {
        for (yi = y1; yi <= y2; yi++)
        {
            putpixel(xi, yi, WHITE);
            if (p >= 0)
            {
                xi++;
                p += 2 * (dx - dy);
            }
            else
            {
                p += 2 * dx;
            }
        }
    }

    putpixel(x2, y2, WHITE);
    getch();
    closegraph();
    return 0;
}
#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int x1 = 10, y1 = 10, x2 = 50, y2 = 30;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int xi = x1, yi = y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    if (dx >= dy)
    {
        for (xi = x1; xi <= x2; xi++)
        {
            putpixel(xi, yi, WHITE);
            if (p >= 0)
            {
                yi++;
                p += 2 * (dy - dx);
            }
            else
            {
                p += 2 * dy;
            }
        }
    }
    else
    {
        for (yi = y1; yi <= y2; yi++)
        {
            putpixel(xi, yi, WHITE);
            if (p >= 0)
            {
                xi++;
                p += 2 * (dx - dy);
            }
            else
            {
                p += 2 * dx;
            }
        }
    }

    putpixel(x2, y2, WHITE);
    getch();
    closegraph();
    return 0;
}
