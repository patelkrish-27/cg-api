#include<stdio.h>
#include<conio.h>
#include<graphics.h>

float rcode(float x,float y,float xmax,float ymax,float xmin,float ymin){
float code = 0;
if(y>ymax){
	code +=8;
	}
if(y<ymin){
	code += 4;
	}
if(x<xmin){
	code += 1;
	}
if(x>xmax){
	code += 2;
	}
return code;
}
void main(){
	int gd = DETECT,gm;

	float x1,y1, x2, y2,xmin,ymin,xmax,ymax,px1,py1,px2,py2;	//interested window points
	float m;
	clrscr();
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	printf("Enter the line points x1 y1 x2 y2 :");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	printf("Enter xmin xmax ymin ymax: ");
	scanf("%f %f %f %f",&xmin,&xmax,&ymin,&ymax);

	int code1 = rcode(x1,y1,xmax,ymax,xmin,ymin);
	int code2 = rcode(x2,y2,xmax,ymax,xmin,ymin);
	if(!(code1 | code2)){
	printf("Accepted");
	}
	else if((code1 &  code2) == 0){
	//finding intersection point
	m = (y2-y1)/(x2-x1);
	if(code1){
		if(x1<=xmin){
			px1 = xmin;
			py1 = y1 +m*(px1-x1);
		}else if(x1>=xmax){
			px1 = xmax;
			py1 = y1 + m*(px1-x1);
		}else if(y1>=ymax){
			py1 = ymax;
			px1 = x1 + (1/m)*(py1-y1);
		}else if(y1<=ymin){
			py1 = ymin;
			px1 = x1 + (1/m)*(py1-y1);
		}
	}
	if(code2){
		if(x2<=xmin){
			px2 = xmin;
			py2 = y2 +m*(px2-x2);
		}else if(x2>=xmax){
			px2 = xmax;
			py2 = y2 + m*(px2-x2);
		}else if(y2>=ymax){
			py2 = ymax;
			px2 = x2 + (1/m)*(py2-y2);
		}else if(y2<=ymin){
			py2 = ymin;
			px2 = x2 + (1/m)*(py2-y2);
		}
	}
	ymin += 100;
	ymax += 100;
	line(x1,y1,x2,y2);
	rectangle(xmin,ymax,xmax,ymin);
	rectangle(200+xmin,ymax,200+xmax,ymin);
	line(px1+200,py1,px2+200,py2);
	}
	getch();
}

// input 1 : 10 120 90 300
//input 2 : 50 100 100 250