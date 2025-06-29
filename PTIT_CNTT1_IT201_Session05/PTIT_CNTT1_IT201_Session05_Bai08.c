#include <stdio.h>
#include <string.h>
int stringToInt(char str[20] , int n , int i ,int number) {
    if (i == n || str[i] == '\n') return number; 
    if(str[i] < '0' || str[i] > '9') return -1;
    number = number*10 + (str[i] - '0');
    i++;
    return stringToInt(str, n, i, number);
}
int main() {
    char str[20];
    printf("nhap mot chuoi: ");
    fgets(str,20,stdin);
    int len = strlen(str);
    int index = 0;
    int numbers= 0;
    int result = stringToInt(str, len, index, numbers);
    if (result == -1) {
        printf("input khong hop le\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}