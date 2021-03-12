// program to fill polygon using floodfill 
// algorithm 
#include <graphics.h> 
#include <stdio.h> 

// flood fill algorithm 
void flood(int x, int y, int new_col, int old_col) 
{ 
	// check current pixel is old_color or not 
	if (getpixel(x, y) == old_col) { 

		// put new pixel with new color 
		putpixel(x, y, new_col); 

		// recursive call for bottom pixel fill 
		flood(x + 1, y, new_col, old_col); 

		// recursive call for top pixel fill 
		flood(x - 1, y, new_col, old_col); 

		// recursive call for right pixel fill 
		flood(x, y + 1, new_col, old_col); 

		// recursive call for left pixel fill 
		flood(x, y - 1, new_col, old_col); 
	} 
} 

int main() 
{ 
	int gd = USER, gm = 500500; 

	// initialize graph 
	initgraph(&gd, &gm, ""); 

	// rectangle coordinate 
	int top, left, bottom, right; 

	top = left = 50; 
	bottom = right = 300; 

	// rectangle for print rectangle 
	rectangle(left, top, right, bottom); 

	// filling start cordinate 
	int x = 75; 
	int y = 75; 

	// new color to fill 
	int newcolor = 4; 

	// new color which you want to fill 
	int oldcolor = 0; 

	// call for fill rectangle 
	flood(x, y, newcolor, oldcolor); 
	getch(); 

	return 0; 
} 

