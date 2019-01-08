#include <stdio.h>
#include "PointSet.h"
#include <math.h>
#define inf 10e8

float pointsDist( point a, point b ){
	float dist = (a.x - b.x)*(a.x - b.x ) + (a.y - b.y)*(a.y - b.y);
	return sqrt(dist);
}

void printDC( PointSet &dc ){
	int i;
	for( i = 0; i < dc.pointCount; i++ ){
		printf("(%d, %d) ", dc.list[i].x, dc.list[i].y);
	}
	printf("\n");
}

void deleteDubl( PointSet &dc ){
	int i, j;
	for( j = 0; j < dc.pointCount - 1; j++ ){
		for( i = j + 1; i < dc.pointCount; i++){
			if((dc.list[j].x == dc.list[i].x) && (dc.list[j].y == dc.list[i].y)){
				dc.list[i].x = dc.list[dc.pointCount - 1].x;
				dc.list[i].y = dc.list[dc.pointCount - 1].y;
				dc.pointCount -= 1;
				//i--;
			}
		}
	}
}

float minDist( PointSet dc ){
	int i, j;
	float minDist = 0, currentDist;
	for( j = 0; j < dc.pointCount - 1; j++ ){
		for( i = j + 1; i < dc.pointCount; i++){
			if( i != j ){
				currentDist = pointsDist(dc.list[j], dc.list[i]);
				if( minDist == 0 ){
					minDist = currentDist;
				}
				if( minDist > currentDist ){
					minDist = currentDist;
				}
			}
		}
	}
	return minDist;
}

int main(){
	PointSet dc;
	int i;
	float dist;

	printf("Input points count: ");
	scanf("%d", &dc.pointCount);
	for( i = 0; i < dc.pointCount; i++ ){
		scanf("%d %d", &dc.list[i].x, &dc.list[i].y);
	}
	printf("Delete All same Point\n");
	printDC(dc);
	deleteDubl(dc);
	printDC(dc);
	dist = minDist(dc);
	printf("Min dist = %0.5f", dist);
}
