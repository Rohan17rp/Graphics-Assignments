#include <graphics.h>
#include <stdio.h>
#include <math.h>

void boundaryFill4(int x, int y, int fillColor, int boundary_color);
int main()
{
	int gd = USER, gm = 400400;	
	
	//Declaring variables
	int x, y, fill_color = 4, boundary_color = 15;

	initgraph(&gd, &gm, NULL);

//	int arr[] = {
//		50, 50,
//	       	100, 60,
//	       	100, 100,
//		75, 80,
//	       	60, 100,
//	       	50, 50
//	};

	int arr[] = {
		50, 50,
		100, 50,
		100, 100,
		50, 100,
		50, 50,
	};

	drawpoly(5, arr);

	x = 75;
	y = 75;

	boundaryFill4(x, y, fill_color, boundary_color);
	
	getch();
	closegraph();
	return 0;
}

void boundaryFill4(int x, int y, int fill_color,int boundary_color) 
{ 
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) 
    { 
        putpixel(x, y, fill_color);
       	delay(1);	
        boundaryFill4(x + 1, y, fill_color, boundary_color); 
        boundaryFill4(x, y + 1, fill_color, boundary_color); 
        boundaryFill4(x - 1, y, fill_color, boundary_color); 
        boundaryFill4(x, y - 1, fill_color, boundary_color); 
    } 
}
