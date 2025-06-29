#include <stdio.h>
#include <stdlib.h> 
void average(int arr[], int n){
    int result=0;
    int count = 0; 
    for(int i = 0 ; i < n ; i++){
        if(arr[i]%2==0){
            result+=arr[i];
            count++;
        }
    }
    int average = result / count;
    printf("average = %d ",average);
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
        printf("nhap cac phan tu cho mang\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        average(arr,n);
    }
    free(arr);
    return 0;
}

