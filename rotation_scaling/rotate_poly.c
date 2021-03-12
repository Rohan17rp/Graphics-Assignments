#include <stdio.h>
#include <graphics.h>
#include <math.h>

int arr[20][2], arr2[20][2];


void draw_poly(int arr[20][2], int n);
void rotate(int arr[20][2], int n, float angle, int x, int y);

int main() {
	int gd = DETECT, gm, n, x1, y1, x2, y2, x3, y3, x, y, i;
	float angle;
	printf("Enter number of edges of polygon : ");
	scanf("%d", &n);
	printf("Enter the coordinates : ");
	for(i = 0; i < n; i++){
		printf("x%d y%d : ",i,i);
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	arr[n][0]=arr[0][0];
	arr[n][1]=arr[0][1];

	printf("Enter the angle of rotation : ");
	scanf("%f", &angle);
	printf("Enter point to rotate along : ");
	scanf("%d %d", &x, &y);
	initgraph(&gd, &gm, " ");
	draw_poly(arr, n);
	getch();
	rotate(arr, n, angle, x, y);
	getch();
	closegraph();
	return 0;
}


void draw_poly(int arr[20][2], int n){
	int i;
	for(i = 0; i < n; i++){
		line(arr[i][0], arr[i][1], arr[i+1][0], arr[i+1][1]);
	}
}

void rotate(int arr[20][2], int n, float angle, int x, int y){
	angle = (angle * 3.14) / 180;
	int i;
	for(i = 0; i < n; i++){
		arr2[i][0] = x + (arr[i][0] - x) * cos(angle) - (arr[i][1] - y) * sin(angle);
		arr2[i][1] = y + (arr[i][0] - x) * sin(angle) + (arr[i][1] - y) * cos(angle);
  	}
  	arr2[n][0]=arr2[0][0];
	arr2[n][1]=arr2[0][1];
	draw_poly(arr2, n);
}
