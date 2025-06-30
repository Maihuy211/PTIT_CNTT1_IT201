#include <stdio.h>
void insertionSort(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        int key = arr[i];
        int j = i - 1 ;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;  
        }
        arr[j+1] = key;
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
    insertionSort(arr,n);
    printf("\n");
    printf("after: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}