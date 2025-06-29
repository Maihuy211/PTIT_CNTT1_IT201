#include <stdio.h>
int sumNumbers(int n){
    if(n == 0){
        return 0;
    }
    return n + sumNumbers(n-1);
}
int main() {
   int n;
   printf("nhap n: ");
   scanf("%d",&n);
   printf("%d",sumNumbers(n));
}