#include <stdio.h>
int main(){
    int count = 0, n=5;
    int arr[] = {1, 4, 5, 3, 7};
    int check = -1;
    printf("Nhap mot so: ");
    scanf("%d", &check);
    int i;
    for(i = 0; i < n; i++){
        if(check == arr[i]){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
// do phuc tap O(n)
    

