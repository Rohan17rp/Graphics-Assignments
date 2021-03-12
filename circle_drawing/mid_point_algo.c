#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

void circlePlotPoints(int xc, int yc, int x, int y);
int main()
{
	int gd = USER, gm = 400400;	
	
	//Declaring variables
	int xc, yc, r, p, x, y;

	//Take input values of center and radius
	printf("Enter Xc, Yc: \n");
	scanf("%d%d", &xc, &yc);
	printf("Enter Radius: \n");
	scanf("%d", &r);
	
	// Return error if radius is zero
	if(r == 0){
		printf("Radius must be non-zero");
		return 1;
	}

	p = 5/(float)4 - (float)r;
	x = 0;
	y = r;

	
	initgraph(&gd, &gm, NULL);
	circlePlotPoints(xc, yc, x, y);
	while(x < y){
		if(p < 0){
			x++;
			p = p + (2 * x) + 1;		
		}
		else{
			x++;
			y--;
			p = p + (2 * x) + 1 - (2 * y);
		}
		//printf("%d, %d\n", x, y);
		circlePlotPoints(xc, yc, x, y);
	}
	
	
	getch();
	closegraph();
	return 0;
}

void circlePlotPoints(int xc, int yc, int x, int y){
	if(xc + x < 400){
		if(yc + y < 400){
			putpixel(xc + x, yc + y, WHITE);
			putpixel(xc + x, yc - y, WHITE);
		}
	}
	if(xc + y){
		putpixel(xc + y, yc + x, WHITE);
		putpixel(xc + y, yc - x, WHITE);
	}
	if(xc - x > 0){
		putpixel(xc - x, yc + y, WHITE);
		putpixel(xc - x, yc - y, WHITE);
	}
	if(xc - y > 0){
		putpixel(xc - y, yc + x, WHITE);
		putpixel(xc - y, yc - x, WHITE);
	}
	delay(100);
}
