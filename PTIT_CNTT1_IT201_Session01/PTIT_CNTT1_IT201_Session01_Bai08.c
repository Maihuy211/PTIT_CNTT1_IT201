#include <stdio.h>
int main(){
    int n = 10;
    int arr[]={2,3,4,5,6,7,7,5,4,7};
    int max=arr[0];
    int max_count = 0 ;
    int i,j;
    for(i = 0 ; i < n ; i++){
        int count = 0 ;
        for(j = 0 ; j < n ; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if( count > max_count){
            max=arr[i];
        }
    }
    printf("phan tu xuat hien nhieu nhat la: %d",max);
    return 0;
}
// do phuc tap O(n^2)
