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
    int check;
    int index = -1 ;
    printf("nhap mot so can tim vi tri: ");
    scanf("%d",&check);
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==check){
            index = i ;
            break;
        }
    }
    if(index){
       printf("vi tri thu %d",index+1);
    }else{
        printf("khong ton tai phan tu");
    }
    return 0;
    // do phuc tap thoi gian : O(n);
}