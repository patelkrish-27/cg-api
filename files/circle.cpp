#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <string.h>

int main()
{

    int gd = DETECT, gm; // graph

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // starting graph

    int r = 100; // radius
    int x = 0, y = r;

    // calculating p
    float p = 1.25 - r;

    do
    {
        putpixel(200 + x, 200 + y, WHITE); // 4th quadrant
        putpixel(200 + y, 200 + x, WHITE);
        putpixel(200 - x, 200 + y, WHITE); // 3rd quadrant
        putpixel(200 - y, 200 + x, WHITE);
        putpixel(200 - x, 200 - y, WHITE); // 2nd quadrant
        putpixel(200 - y, 200 - x, WHITE);
        putpixel(200 + x, 200 - y, WHITE); // 1st quadrant
        putpixel(200 + y, 200 - x, WHITE);

        if (p < 0)
        {
            x++;
            p += 2 * x + 1;
        }
        else
        {
            x++;
            y--;
            p += 2 * (x - y) + 1;
        }

    } while (x < y);

    getch();
}
