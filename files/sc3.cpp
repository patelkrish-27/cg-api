#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{

    int gd = DETECT, gm, sx, sy, sz;

    initgraph(&gd, &gm, "c:\\TC\\BGI");

    bar3d(100, 100, 300, 200, 10, 1);

    printf("Enter the sx,sy,sz:");
    scanf("%d %d %d", &sx, &sy, &sz);
    bar3d(100 * sx, 100 * sy, 300 * sx, 200 * sy, 10 * sz, 1);
    getch();
}