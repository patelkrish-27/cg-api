#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm, sx, sy;
    initgraph(&gd, &gm, "c:\\TC\\BGI");
    rectangle(100, 100, 200, 200);
    printf("Enter the sx,sy:");
    scanf("%d %d", &sx, &sy);
    rectangle(100 * sx, 100 * sy, 200 * sx, 200 * sy);
    getch();
}