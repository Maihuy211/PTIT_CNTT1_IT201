#include <stdio.h>
void merge(int arr[], int l ,int mid, int r){
    int i , j , k;
    int leftArrSize = mid - l + 1;
    int rightArrSize = r - mid;
    int leftArr[leftArrSize] , rightArr[rightArrSize];
    for(i = 0 ; i < leftArrSize ; i++){
        leftArr[i] = arr[l + i];
    }
    for(j = 0; j < rightArrSize; j++) {
        rightArr[j] = arr[mid + 1 + j];  
    }
    i = 0 , j = 0 ,k = l;
    while(i < leftArrSize && j <  rightArrSize ){
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while(i < leftArrSize){
        arr[k++] = leftArr[i++];
    }
    while(j < rightArrSize){
        arr[k++] = rightArr[j++];
    }
}
void mergeSort(int arr[], int l, int r){
    if(l == r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
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
        mergeSort(arr, 0, n - 1);
        for(int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]);
        }
    }
    return 0;
    // độ phức tạp thời gian O(nlogn);
}