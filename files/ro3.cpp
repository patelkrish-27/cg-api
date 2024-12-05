#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{

    int gd = DETECT, gm, l = 100, t = 100, r = 300, b = 200, x1, y1, x2, y2;
    float a, rd;
    initgraph(&gd, &gm, "c:\\TC\\BGI");
    bar3d(l, t, r, b, 10, 1);
    printf("Enter the angle to rotate");
    scanf("%f", &a);
    r = a * 3.14 / 180.0;

    x1 = l * cos(rd) - t * sin(rd);
    y1 = l * sin(rd) + t * cos(rd);

    x2 = r * cos(rd) - b * sin(rd);
    y2 = r * sin(rd) + b * cos(rd);

    // bar3d(x1,y1,x2,y2,10,1);
    bar3d(100, 150, 250, 250, 10, 1);
    getch();
}