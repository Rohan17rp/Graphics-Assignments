#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "header.h"


int main()
{
	int gd = USER, gm = 400400;	
	
	//Declaring variables
	int x1, y1, x2, y2, dx, dy, twoDy, twoDxDy, p, x, y, steps;
	

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

	int i = 0;
	if(dx > dy){
		steps = dx;	
		twoDy = 2 * dy;
		twoDxDy = 2 * (dy - dx);
		p = (2 * dy) - dx;
		x = x1;
		y = y1;
	}
	else{
		steps = dy;
		twoDy = 2 * dx;
		twoDxDy = 2 * (dx - dy);
		p = (2 * dx) - dy;
		x = y1;
		y = x1;
	}

	PixelPos pixel_pos[steps];
	
	while(i < steps){
		if(p < 0){
			p = p + twoDy;
			if(x2 > x1){
			       	x++;
			}
			else{
				x--;
			}
		}
		else{
			p = p + twoDxDy;
			if(x2 > x1){
			       	x++;
			}
			else{
				x--;
			}
			if(y2 > y1){
			       	y++;
			}
			else{
				y--;
			}
		}		
		pixel_pos[i].x = x;
		pixel_pos[i].y = y;
		printf("%d, %d\t ", y, x);
		i++;
	}

	initgraph(&gd, &gm, NULL);
	
	if(dx > dy){
		for(i = 0; i < dx; i++){
			putpixel(pixel_pos[i].x, pixel_pos[i].y, RED);
		}
	}
	else{
		for(i = 0; i < dy; i++){
			putpixel(pixel_pos[i].y, pixel_pos[i].x, RED);
	
		}
	}	
	getch();

	closegraph();
	return 0;
}
