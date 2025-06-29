#include<stdio.h>
int* mallocArray(int n){
	int* arr = (int*)malloc(n * sizeof(int n));
	for(int i = 0 ; i < n ; i++){
		arr[i]=i;
	}
	return arr;
}
// do phuc tap khong gian O(n)