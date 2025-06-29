#include <stdio.h>
void binaryNumber(int n){
    if(n == 0 ){
        return;
    }
    binaryNumber(n/2);
    printf("%d ",n%2);
}
int main() {
   int n;
   printf("nhap n: ");
   scanf("%d",&n);
   binaryNumber(n);
}