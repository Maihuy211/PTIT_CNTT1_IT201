#include <stdio.h>
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
    int index = -1 ;
    printf("nhap mot gia tri bat ki: ");
    scanf("%d",&check);
    int right = 0 ;
    int end = n - 1 ;
    while (end <= right) {
        int mid = (end + right) / 2;
        if (arr[mid] == check) {
            index = mid;
            break;
        } else if (arr[mid] < check) {
            end = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(!index){
        printf("phan tu ko co trong mang");
    }else{
        printf("phan tu co trong mang");
    } 
    return 0;
}