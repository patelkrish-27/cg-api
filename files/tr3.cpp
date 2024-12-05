#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\TC\\BGI");
    bar3d(100, 100, 300, 200, 10, 1);
    printf("Enter the tx,ty:");
    scanf("%d %d", &tx, &ty);
    bar3d(100 + tx, 100 + ty, 300 + tx, 200 + ty, 10, 1);
    getch();
}