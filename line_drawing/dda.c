#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int gd = USER, gm = 100100;	
	
	//Declaring variables
	int x1, y1, x2, y2;
	float dx, dy, step;
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
	dy = y2 - y1;
	
	// setting number of pixels required to draw
	if(dx >= dy){
		step = dx;
	}
	else{
		step = dy;
	}
	
	dx = dx/step;
	dy = dy/step;

	x = x1;
	y = y1;

	initgraph(&gd, &gm, NULL);
	
	int i = 1;
	while(i <= step){
		putpixel(x, y, RED);
		x = x + dx;
		y = y + dy;
		i = i + 1;
		delay(100);
	}

	
	
	getch();
	closegraph();
	return 0;
}
