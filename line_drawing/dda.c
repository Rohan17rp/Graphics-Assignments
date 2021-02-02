#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

int main()
{
	int gd = USER, gm = 400400;	
	
	//Declaring variables
	int x1, y1, x2, y2, dx, dy, step;
	float xinc, yinc;
	float x, y;

	//Take input values of start and end positions
	printf("Enter X1, Y1: \n");
	scanf("%d%d", &x1, &y1);
	printf("Enter X2, Y2: \n");
	scanf("%d%d", &x2, &y2);
	
	// Return error if start and end points are same
	if(x1 ==  x2 && x2 == y2){
		printf("Start and end points must be different");
		return 1;
	}
	
	// Calculating dx and dy
	dx = x2 - x1;
	if(dx < 0){
		dx *= -1;
	}

	dy = y2 - y1;
	if(dy < 0){
		dy *= -1;
	}
	
	// setting number of pixels required to draw
	if(dx > dy){
		step = dx;
	}
	else{
		step = dy;
	}

	x = x1;
	y = y1;
	
	xinc = dx/(float)step;
	yinc = dy/(float)step;

	PixelPos pixelpos[step + 1];

	pixelpos[0].x = x;
	pixelpos[0].y = y;
	int i = 1;
	for(i = 1; i < step + 1; i++){
		if(x2 > x1){
			x = x + xinc;
		}
		else{
			x = x - xinc;
		}
		if(y2 > y1){
			y = y + yinc;
		}
		else{
			y = y - yinc;
		}
		pixelpos[i].x = ROUND(x);
		pixelpos[i].y = ROUND(y);
		printf("%d, %d\n", ROUND(x), ROUND(y));
	}

	initgraph(&gd, &gm, NULL);
	
	for(i = 0; i < step + 1; i++){
		putpixel(pixelpos[i].x, pixelpos[i].y, RED);
	}
	
	getch();
	closegraph();
	return 0;
}
