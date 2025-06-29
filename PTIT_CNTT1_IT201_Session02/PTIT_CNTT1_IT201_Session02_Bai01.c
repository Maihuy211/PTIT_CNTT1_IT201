#include <stdio.h>
#include <stdlib.h> 
void checkmax(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Max: %d\n", max);
}
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
        scanf("%d", &arr[i]);
    }
    checkmax(arr,n);
    free(arr);
    return 0;
}

