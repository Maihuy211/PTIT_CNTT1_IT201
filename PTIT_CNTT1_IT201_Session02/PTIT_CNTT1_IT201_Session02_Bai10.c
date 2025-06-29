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
    for(int i = 0 ; i < n ; i++){
        int count = 1 ; 
        int check = 0;
        for(int j = 0 ; j < i ; j++ ){
            if(arr[j]==arr[i]){
                check = 1;
                break;
            }
        }
        if(check){
            continue;
        }
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        printf("phan tu %d xuat hien %d lan \n",arr[i],count);
    }
    free(arr);
	return 0; 
}

