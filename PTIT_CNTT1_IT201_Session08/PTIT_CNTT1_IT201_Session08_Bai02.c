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
    int check;
    int index = -1 ;
    printf("nhap mot gia tri bat ki: ");
    scanf("%d",&check);
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
        printf("vi tri thu %d", index + 1);
    } else {
        printf("khong ton tai phan tu");
    }
    return 0;
    // độ phức tạp thời gian là O log n
}