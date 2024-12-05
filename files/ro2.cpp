#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int x1_rot, y1_rot, x2_rot, y2_rot;
    float angle, radian;
    clrscr();

    initgraph(&gd, &gm, "c:\\TC\\BGI");

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    line(x1, y1, x2, y2);

    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);

    radian = angle * 3.14 / 180.0;

    x1_rot = (x1 * cos(radian) - y1 * sin(radian));
    y1_rot = (x1 * sin(radian) + y1 * cos(radian));

    x2_rot = (x2 * cos(radian) - y2 * sin(radian));
    y2_rot = (x2 * sin(radian) + y2 * cos(radian));

    line(x1_rot, y1_rot, x2_rot, y2_rot);

    getch();
}
