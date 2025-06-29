#include <stdio.h>
#include <stdlib.h> 
int main() {
    int n;
    int *arr;
    do{
       printf("Nhap n: ");
       scanf("%d", &n);
    }while(n < 0 || n >= 100);
    arr = (int *)malloc(n * sizeof(int));
    printf("nhap cac phan tu cho mang\n");

    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    int *arr2 = (int *)malloc(n * sizeof(int)); 
    int max = arr[n - 1];
    int count = 0;
    arr2[count++] = max;
    for(int i = n - 2 ; i >= 0 ; i--) {
        if(arr[i]>max){
            max = arr[i];
            arr2[count++] = arr[i];
        }
    }
    for(int i = count - 1  ; i >= 0 ; i--){
        printf("%d ",arr2[i]);
    }
    free(arr);
    free(arr2);
	return 0; 
}



