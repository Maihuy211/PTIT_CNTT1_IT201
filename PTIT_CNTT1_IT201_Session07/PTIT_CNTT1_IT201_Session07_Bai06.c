#include <stdio.h>
void merge(int arr[], int l ,int mid, int r){
    // b1: tao ra 2 mang con ben trai va ben phai
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
    // b3: tron 2 mang con lai trong mang cha
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
    // xay dung dieu kien dung 
    if(l == r){
        return;
    }
    // giai quyet bai toan con voi trai ben trai
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    // giai quyet bai toan con voi phan ben phai
    mergeSort(arr,mid+1,r);
    // tron cac mang con lai
    merge(arr,l,mid,r);
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
    mergeSort(arr, 0, n - 1);
    printf("\n");
    printf("after: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}