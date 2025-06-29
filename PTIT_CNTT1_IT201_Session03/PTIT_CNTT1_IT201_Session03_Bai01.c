#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n;
    int *arr;
    printf("Nhap n: ");
    scanf("%d", &n);
    if(n < 0){
        printf("so luong phan tu ko dc am");
    }else if(n == 0){
        printf("so luong phan tu lon hon 0");
    }else if(n > 1000){
        printf("Khong hop le");
    }else{
        arr = (int *)malloc(n * sizeof(int));
        printf("nhap cac phan tu cho mang\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for(int i = 0 ; i < n ; i++){
            printf("So thu %d = %d\n",i+1,arr[i]);
        }
    free(arr);
    } 
    return 0;
}

