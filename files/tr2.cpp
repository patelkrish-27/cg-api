#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{

    int gd = DETECT, gm;
    int tx, ty;

    initgraph(&gd, &gm, "c:\\TC\\BGI");
    printf("Before:");
    rectangle(100, 100, 300, 200);
    printf("Enter tx and ty:");
    scanf("%d %d", &tx, &ty);
    printf("after:");
    rectangle(100 + tx, 100 + ty, 300 + tx, 200 + ty);
    getch();
}
