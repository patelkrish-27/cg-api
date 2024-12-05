#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
	int gd = DETECT,gm;
	int x1,x2,y2,y1 ,c,x,y,b,r, yb;
	clrscr();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("enter ltrb");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	line(x2,y2,x2,y1);
	printf("enter choice");
   scanf("%d",&c);

	switch(c){
		case 1:
		printf("enter for xshear");
		scanf("%d",&x);
	      b = x+x1;
		r = x+x2;
	line(b,y1,r,y1);
	line(b,y1,x1,y2);
	line(x1,y2,x2,y2);
	line(x2,y2,r,y1);



	}
	getch();
	closegraph();
	}
