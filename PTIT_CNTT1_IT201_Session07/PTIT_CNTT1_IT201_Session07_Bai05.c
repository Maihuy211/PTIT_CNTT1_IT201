#include <stdio.h>
int partition(int arr[] , int l , int r){
    int pivot = arr[(l+r)/2] , i = l , j = r ;
    while(i <= j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j] ;
            arr[j] = temp ;
            i++;
            j++;
        }
        return i;
    }
}
void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi, r);
    }
}
int main(){
    int n;
    printf("nhap so phan tu cho mang: ");
    scanf("%d",&n);
    if(n <= 0){
        printf("so luong phan tu khong hop le: ");
    }else{
        int arr[100];
        printf("nhap cac phan tu cho mang: \n");
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);
        }
        printf("before: ");
        for(int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]);
        }
        quickSort(arr, 0, n - 1);
        printf("\n");
        printf("after: ");
        for(int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}