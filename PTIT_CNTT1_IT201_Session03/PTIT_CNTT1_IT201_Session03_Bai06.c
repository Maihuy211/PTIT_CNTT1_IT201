#include <stdio.h>
#include <stdlib.h> 
void printArray(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    int *arr;
       printf("Nhap n: ");
       scanf("%d", &n);
    if(n <= 0 || n >= 1000){
       printf("so luong phan tu ko hop le");
    }else{
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int m;
        printf("nhap m so muon the: ");
        scanf("%d",&m);
        int pos = n;
        n = m + n;
        arr = (int *)realloc(arr, n * sizeof(int));
        for(int i = pos ; i < n ; i++){
            scanf("%d",&arr[i]);
        }
        printf("Mang sau khi them:\n");
        printArray(arr,n);
        free(arr);
    }
}