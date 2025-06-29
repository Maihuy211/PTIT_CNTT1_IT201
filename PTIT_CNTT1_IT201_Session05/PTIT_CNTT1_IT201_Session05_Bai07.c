#include <stdio.h>
int fibonacci(int n) {
    if(n == 0 ) {
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibonacci(n-1) +  fibonacci(n-2);
    
}
int main() {
    int n;
    int fibo[100];
    printf("nhap n: ");
    scanf("%d",&n);
    if(n>0){
        for(int i = 0 ; i < n ; i++){
            fibo[i] = fibonacci(i); 
            printf("%d ", fibo[i]); 
        }
    }else{
        printf("input khong hop le");
    }
    return 0;
}