#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

void ellipsePlotPoints(int xc, int yc, int x, int y);
int main()
{
	int gd = USER, gm = 400400;	
	
	//Declaring variables
	int xc, yc, rx, ry, p1, p2, x, y;
	int rxsquare, rysquare, twoRxSquareY, twoRySquareX;

	//Take input values of center and radius
	printf("Enter Xc, Yc: \n");
	scanf("%d%d", &xc, &yc);
	printf("Enter Rx, Ry: \n");
	scanf("%d%d", &rx, &ry);
	
	// Return error if radius is zero
	if(rx == 0 || ry == 0){
		printf("Radius must be non-zero");
		return 1;
	}
	
	x = 0;
	y = ry;
	
	rysquare = ry * ry;
	rxsquare = rx * rx;
	twoRxSquareY = 2 * rxsquare * y;
	twoRySquareX = 2 * rysquare * x;
	p1 = (rysquare) - (rxsquare * ry) + (rxsquare / 4);

	initgraph(&gd, &gm, NULL);
	
	ellipsePlotPoints(xc, yc, x, y);
	while(twoRySquareX < twoRxSquareY){
		if(p1 < 0){
			x++;
			rxsquare = rx * rx;
			twoRxSquareY = 2 * rxsquare * y;
			twoRySquareX = 2 * rysquare * x;
			
			p1 = p1 + twoRySquareX + rysquare;
		}
		else{
			x++;
			y--;
			rysquare = ry * ry;
			rxsquare = rx * rx;
			twoRySquareX = 2 * rysquare * x;
			twoRxSquareY = 2 * rxsquare * y;
			
			p1 = p1 + twoRySquareX - twoRxSquareY + rysquare;
		}
		ellipsePlotPoints(xc, yc, x, y);
	}

	p2 = (rysquare * (x + 0.5) * (x + 0.5)) + (rxsquare * (y - 1) * (y - 1)) - (rxsquare * rysquare);
	while(y > 0){
		if(p2 > 0){
			y--;
			rysquare = ry * ry;
			twoRySquareX = 2 * rysquare * x;
			twoRxSquareY = 2 * rxsquare * y;
			
			p2 = p2 - 2 * rxsquare * y + rxsquare;
		}
		else{
			x++;
			y--;	
			rysquare = ry * ry;
			rxsquare = rx * rx;
			twoRySquareX = 2 * rysquare * x;
			twoRxSquareY = 2 * rxsquare * y;

			p2 = p2 + twoRySquareX - twoRxSquareY + rxsquare;
		}
		ellipsePlotPoints(xc, yc, x, y);
	}
	
	
	getch();
	closegraph();
	return 0;
}

void ellipsePlotPoints(int xc, int yc, int x, int y){
	putpixel(xc + x, yc + y, RED);
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc + y, RED);
	putpixel(xc - x, yc - y, RED);
}
