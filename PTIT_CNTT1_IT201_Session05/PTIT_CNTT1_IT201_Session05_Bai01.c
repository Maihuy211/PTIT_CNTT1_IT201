#include <stdio.h>
void countNumbers(int n,int count){
    if(count > n ){
        return;
    }
    printf("%d ",count);
    count++;
    countNumbers(n,count); 
}
int main() {
   int n;
   int count = 1;
   printf("nhap n: ");
   scanf("%d",&n);
   countNumbers(n,count);
}