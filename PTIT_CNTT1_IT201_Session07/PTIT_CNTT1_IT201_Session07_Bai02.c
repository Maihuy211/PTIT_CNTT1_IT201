#include <stdio.h>
void selectionSort(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        int min = i;
        for( int j = i + 1 ; j < n ; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }
}
int main(){
    int n;
    printf("nhap so phan tu cho mang: ");
    scanf("%d",&n);
    int arr[100];
    printf("nhap cac phan tu cho mang: \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("before: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    selectionSort(arr,n);
    printf("\n");
    printf("after: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}