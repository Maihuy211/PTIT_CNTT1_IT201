#include <stdio.h>
void maxMinArray(int arr[],int n, int i,int max,int min){
   if(i==n){
    printf("%d, %d",min,max);
    return;
   }
   if(arr[i]>max){
      max=arr[i];
   }
   if(arr[i]<min){
      min = arr[i];
   }
    maxMinArray(arr,n,i+1,max,min);
}
int main(){
   int arr[100];
   int n;
   printf("nhap n: ");
   scanf("%d",&n);
   printf("nhap cac phan tu cho mang: \n");
   for(int i = 0 ; i < n ; i++){
      printf("arr[%d]= ",i);
      scanf("%d",&arr[i]);
   }
   int min = arr[0] , max = arr[0];
   maxMinArray(arr,n,1,max,min);
   return 0;
}