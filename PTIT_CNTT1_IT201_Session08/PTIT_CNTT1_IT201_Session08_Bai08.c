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
    if(n<=0){
         printf("so luong phan tu khong hop le");
    }else{
        int arr[100];
        printf("nhap cac phan tu cho mang: \n");
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);
        }
        printf("mang ban dau la:  ");
        for(int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]);
        }
        insertionSort(arr,n);
        printf("\nmang sau khi sap xep: ");
        for(int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]);
        }
        int check;
        int index = -1 ;
        printf("\nnhap mot so can tim: ");
        scanf("%d",&check);
        for(int i = 0 ; i < n ; i++){
            if(arr[i]==check){
                index = i ;
                break;
            }
        }
        if(index){
        printf("\ntim kiem tuyen tinh: vi tri thu %d",index+1);
        }else{
            printf("tim kiem tuyen tinh: khong ton tai phan tu");
        }
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == check) {
                index = mid;
                break;
            } else if (arr[mid] < check) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (index != -1) {
            printf("\ntim kiem nhi phan : vi tri thu %d", index + 1);
        } else {
            printf("\ntim kiem nhi phan : khong ton tai phan tu");
        }
    }
    return 0;
}