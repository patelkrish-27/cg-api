#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm, c;
    initgraph(&gd, &gm, "c:\\TC\\BGI");
    rectangle(100, 100, 300, 200);

    printf("\nEnter the choice \n1. reflect-x\n2. reflect-y\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        rectangle(640 - 100, 100, 640 - 300, 200);
        break;
    case 2:
        rectangle(100, 480 - 100, 300, 480 - 200);
        break;
    default:
        printf("Invalid code");
    }

    getch();
}