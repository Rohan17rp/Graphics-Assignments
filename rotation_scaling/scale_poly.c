#define MAX_STACK 10
#include<stdio.h>
#include<graphics.h>

void scale(int**, int sx, int sy);
int* scale_point(int* point, int x, int y, int sx, int sy, int sax, int say);
int main(){
	//initialising graphic mode and graphic drivers
	int gd = DETECT, gm; 
	int n, i;
	int point[2];
	int sax, say, sx, sy;
	printf("Enter number of points\n");
	scanf("%d", &n);
	int points[n][2];
	int result[n][2];
	for(i = 0; i < n; i++){
		scanf("%d%d", &points[i][0], &points[i][1]);
	}
	printf("Enter scale x and y respectively\n");
	scanf("%d%d", &sx, &sy);
	printf("Enter point to scale along\n");
	scanf("%d%d", &sax, &say); 
	for(i = 0; i < n; i++){
		int* ptr = scale_point(point, points[i][0], points[i][1], sx, sy, sax, say);
		result[i][0] = ptr[0];
		result[i][1] = ptr[1];
	}
	initgraph (&gd, &gm, NULL); 
	for(i = 0; i < n; i++){
		//printf("%d\t%d\n", result[i][0], result[i][1]);
		if(i == n - 1){
			line(points[i][0], points[i][1], points[0][0], points[0][1]);
		}
		else{
			line(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
		}
	}
	for(i = 0; i < n; i++){
		//printf("%d\t%d\n", result[i][0], result[i][1]);
		if(i == n - 1){
			line(result[i][0], result[i][1], result[0][0], result[0][1]);
		}
		else{
			line(result[i][0], result[i][1], result[i + 1][0], result[i + 1][1]);
		}
	}
	getch();
	return 0;
}

int* scale_point(int* point, int x, int y, int sx, int sy, int sax, int say){
	point[0] = sax + (x - sax) * sx;
	point[1] = say + (y - say) * sy;	
	return point;
}

