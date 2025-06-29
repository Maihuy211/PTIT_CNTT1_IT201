#include <stdio.h>
int searchBinary(int arr[],int end ,int right, int check){
    if(end > right){
        return -1;
    }
    int mid = (right + end)/2;
    if(arr[mid]==check){
        return mid;
    } else if (arr[mid] < check) {
            return searchBinary(arr,mid + 1,right,check);
        } else {
            return searchBinary(arr,end,mid-1,check);
        }
}
int main() {
    int n ,arr[n];
    printf("nhap so luong mang: ");
    scanf("%d",&n);
    printf("nhap cac phan tu cho mang\n");
    for(int i = 0 ; i < n ; i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1  ; j++){
             if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
             }
        }
    }
    printf("mang la: \n");
    for(int i = 0 ; i < n ; i++){
        printf("arr[%d]= %d\n",i,arr[i]);
    }
    int check;
    int end = 0, right = n-1;
    printf("nhap mot gia tri bat ki: ");
    scanf("%d",&check);
    int index = searchBinary(arr,end,right,check);
    if(index==-1){
        printf("phan tu ko co trong mang");
    }else{
        printf("phan tu co trong mang");
    } 
    return 0;
}