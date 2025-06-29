#include <stdio.h>
int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
int totalNumberOfPaths(int row, int col) {
    return factorial(row) / (factorial(col) * factorial(row - col));
}
int main() {
    int row, col;
    printf("nhap so hang: ");
    scanf("%d", &row);
    printf("nhap so cot: ");
    scanf("%d", &col);
    
    int result = totalNumberOfPaths(row+ col - 2, row - 1);
    printf("%d\n", result);
    return 0;
}
