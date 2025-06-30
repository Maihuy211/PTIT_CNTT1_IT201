#include <stdio.h>

int main(){
    int n;
    int arr[100];
    int am[100];
    int duong[100];
    int temp[100];
    int count_am = 0 , count_duong = 0 , count_ko = 0;
    printf("nhap so phan tu cho mang: ");
    scanf("%d",&n);
    if(n <= 0){
        printf("so luong phan tu khong hop le: ");
    }else{
        printf("nhap cac phan tu cho mang: \n");
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);

            if (arr[i] < 0){
                am[count_am++] = arr[i];
            }
            else if (arr[i] > 0){
                duong[count_duong++] = arr[i];
            }else{
                count_ko++;
            }           
        }
        int count = 0;
        for(int i = count_am - 1 ; i >= 0  ; i--){
            temp[count++] = am[i];
        }
        for(int i = 0 ; i < count_ko ; i++){
            temp[count++] = 0;
        }
        for(int i = count_duong - 1 ; i >= 0 ; i--){
            temp[count++] = duong[i];
        }
        for(int i = 0 ; i < n ; i++){
            printf("%d ",temp[i]);
        }
    }
    return 0;
}