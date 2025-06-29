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
    int max=0;
    int max_count = 0;
    for(int i = 0 ; i < n ; i++){
        int count = 0;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count > max_count){
            max=arr[i];
            max_count=count;
        }
    }
    printf("%d",max);
    free(arr);
	return 0; 
}

