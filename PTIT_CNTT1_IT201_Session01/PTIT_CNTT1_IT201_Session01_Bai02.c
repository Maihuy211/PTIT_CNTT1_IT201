#include<stdio.h>
void printDouble(int n){
	int i = 1;
	while(i<n){
		printf("%d/n",i);
		i *= 2;
	}
}
// do phuc tap thoi gian O(log n)
