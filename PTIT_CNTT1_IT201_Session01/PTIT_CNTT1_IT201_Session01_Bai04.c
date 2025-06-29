#include <stdio.h>
int main() {
    // cách 1 
    int n=10;
    int sum1 = 0;
    for (int i = 0 ; i < n ; i++){
        sum1 += i ;
    }
    printf("%d",sum1);
    // độ phức tạp không gian O(n)
    
    // cách 2
    int sum2 = n*(n+1)/2;
    printf("%d",sum2);
    // độ phức tạp không gian O(1)
}