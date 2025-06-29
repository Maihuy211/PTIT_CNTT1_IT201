#include <stdio.h>
// so sanh 
void cach_1(int arr[] , int n){
    int check = 0;
    for(int i = 0 ; i < n -1 ; i++){
        for(int j = i + 1 ; j < n ; j ++){
            if(arr[i]== arr[j]){
               check=1;
               break;
            }
        }
        if(check) break;
    }
    if(check){
        printf("co phan tu trung lap trong mang\n");
    }else{
        printf("ko co phan tu trung lap trong mang\n");
    }
}
// độ phức tap thời gian: O(n^2) không gian : O(1)
// sap xep roi ktra ki tu lien ke
void cach_2(int arr[], int n){
    int check=0;
    for(int i = 0 ; i < n ; i++){
        for(int j=0 ; j < n - 1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i = 0 ; i < n - 1; i++){
        if(arr[i]==arr[i+1]){
            check=1;
            break;
        }
    }
    if(check){
        printf("co phan tu trung lap trong mang\n");     
    }else{
        printf("ko co phan tu trung lap trong mang\n");
    }
}
// độ phức tap thời gian: O(n^2) không gian : O(1)
int main(){
    int arr[]={3,5,7,1,5}; 
    int n = 5;

    cach_1(arr,n);
    cach_2(arr,n);
    return 0;
}