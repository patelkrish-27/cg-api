#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void xshear(int shx)
{
    line(100 + shx, 100, 100, 200);
    line(100 + shx, 100, 200 + shx, 100);
    line(100, 200, 200, 200);
    line(200 + shx, 100, 200, 200);
}
void yshear(int shy)
{
    line(100, 100, 100, 200 - shy);
    line(100, 100, 200, 100);
    line(100, 200 - shy, 200, 200 - shy);
    line(200, 100, 200, 200 - shy);
}
void main()
{

    int gd = DETECT, gm, shx, shy, c;
    initgraph(&gd, &gm, "c:\\TC\\BGI");
    rectangle(100, 100, 200, 200);
    printf("Ente the choice:\n1. x-shear\n2. y-shear:\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter the shx:");
        scanf("%d", &shx);
        xshear(shx);
        break;
    case 2:
        printf("Enter the shy:");
        scanf("%d", &shy);
        yshear(shy);
        break;
    }
    getch();
}