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
    int x;
    printf("nhap mot so:");
    scanf("%d",&x);
    int check=0;
    for(int i = 0 ; i < n -1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[i] + arr[j] == x){
                printf("%d, %d",arr[i],arr[j]);
                check=1;
                break;

            }
        }
    }
    if(check==0){
        printf("Khong tim thay");
    }
    free(arr);
	return 0; 
}



