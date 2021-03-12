#include <stdio.h>
#include <math.h>
#include <graphics.h>

void draw(int x1, int y1, int x2, int y2, int depth) {
	bar3d(x1, y1, x2, y2, depth, 1);
}

void scale(int x1, int y1, int x2, int y2, int x, int y, int sx, int sy) {
	int a1, a2, b1, b2, dep;
	a1 = x1 * sx + (1 - sx) * x;
	b1 = y1 * sy + (1 - sy) * y;
	a2 = x2 * sx + (1 - sx) * x;
	b2 = y2 * sy + (1 - sy) * y;
	dep = (a2 - a1) / 4;
	setcolor(2);
	bar3d(a1, b1, a2, b2, dep, 1);   
}

void main() {
	int x1, x2, y1, y2, mx, my, depth, x, y, sx, sy;
	int gd = DETECT, gm, c;
	printf("Enter left top value : ");
	scanf("%d %d", &x1, &y1);
	printf("Enter right bottom value : ");
	scanf("%d %d", &x2, &y2);
	printf("Enter scaling co-ordinates : ");
	scanf("%d %d", &sx, &sy);
	printf("Enter fixed point : ");
	scanf("%d %d", &x, &y);
	depth = (x2 - x1) / 4;
	initgraph(&gd, &gm, " ");
	draw(x1, y1, x2, y2, depth);
	getch();
	scale(x1, y1, x2, y2, x, y, sx, sy);
	getch();
}
