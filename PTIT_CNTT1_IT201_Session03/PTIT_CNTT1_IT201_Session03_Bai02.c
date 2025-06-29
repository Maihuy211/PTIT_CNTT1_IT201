#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n;
    int *arr;
       printf("Nhap n: ");
       scanf("%d", &n);
    if(n <= 0 || n >= 1000){
       printf("so luong phan tu ko hop le");
    }else{
        arr = (int *)malloc(n * sizeof(int));
        printf("nhap cac phan tu cho mang\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        printf("Max= %d\n", max);
    }
    free(arr);
    return 0;
}

