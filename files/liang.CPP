#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2dx, dy, xmin, ymin, xmax, ymax, u1, u2, min = 1, max = 0;
    float q[4], p[4];
    clrscr();
    printf("Enter the window coordinates xmin,xmax,ymin,ymax:");
    scanf("%f,%f,%f,%f", &xmin, &xmax, &ymin, &ymax);
    printf("Enter the line Coordinates x1,x2,y1,y2:");
    scanf("%f %f %f %f", &x1, &x2, &y1, &y2);
    initgraph(&gd, &gm, "c:\\TURBOC#\\BGI");
    printf("Line before clipping");
    rectangle(xmin, ymax, xmax, ymin);
    line(x1, y1, x2, y2);
    dx = x2 - x1;
    dy = y2 - y1;
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = -dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (int i = 0; i < 4; i++)
    {
        if (p[i] < 0)
        {
            if (max < q[i] / p[i])
            {
                max = q[i] / p[i];
            }
        }
        u1 = max;
        u2 = min;
    }

    if (u1 < u2)
    {
        x1 = x1 + (u1 * dx);
        y1 = y1 + (u1 * dy);
        x2 = x1 + (u2 * dx);
        y2 = y1 + (u2 * dy);
    }
    getch();
    cleardevice();
    printf("line after clipping");
    rectangle(xmin, ymax, xmax, ymin);
    line(x1, y1, x2, y1);
    getch();
}
