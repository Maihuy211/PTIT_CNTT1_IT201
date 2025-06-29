#include <stdio.h>
int total(int n, int m) {
    if (n == m) {
        return 0;
    }
    return n + total(n, m+1);
}
int main() {
    int firstNum;
    int secondNum;
    int max;
    int min;
    printf("nhap firstNum: ");
    scanf("%d", &firstNum);
    printf("nhap secondNum: ");
    scanf("%d", &secondNum);
    if (firstNum > 0 && secondNum > 0) {
        if (firstNum < secondNum) {
            max = secondNum;
            min = firstNum;
        }else {
            min = secondNum;
            max = firstNum;
        }
        printf("%d", total(max, min));
    }
    else {
        printf("khong hop le");
    }
    return 0;
}