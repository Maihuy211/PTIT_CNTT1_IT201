#include <stdio.h>
int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    if(n>0){
       printf("%d",factorial(n));
    }else{
       printf("khong hop le");
    }
    return 0; 
}