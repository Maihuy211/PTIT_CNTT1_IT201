#include <stdio.h>
int countSteps(int n){
   if(n == 0 || n==1){
      return 1;
   }
   return countSteps(n-1)+countSteps(n-2);
}
int main(){
   int n;
   printf("so bac thang: ");
   scanf("%d",&n);
   printf("%d",countSteps(n));
   return 0;
}