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
    printf("mang la: \n");
    for(int i = 0 ; i < n ; i++){
        printf("arr[%d]= %d\n",i,arr[i]);
    }
    int found = -1 ;
    for(int i = 0 ; i < n/2 ; i++){
        if(arr[i]==arr[n-1-i]){
            printf("Cap so doi xung (%d, %d)\n",arr[i],arr[n-i-1]);
            found=i;
        }
    }
    if(found==-1) printf("khong co so doi xung");
    return 0;
}