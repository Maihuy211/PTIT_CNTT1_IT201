#include <stdio.h>
void bubbleSort(int arr[], int n){
    int check = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = 1;
            }
        }
        if(check==0) break;
    }
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
    bubbleSort(arr,n);
    printf("\n");
    printf("after: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}