#include <stdio.h>
#include <string.h>
int palindromeValid(char str[20] , int n , int i) {
    if(i >= n/2){
        return 1;
    }
    if(str[i] != str[n-i-1]){
        return 0;
    }
    i++;
    return palindromeValid(str,n,i);
}
int main() {
    char str[20];
    printf("nhap mot chuoi: ");
    fgets(str,20,stdin);
    int len = strlen(str) - 1;
    int index=0;
    int result = palindromeValid(str,len,index);
    if(result){
        printf("Palindrome valid");
    }else{
        printf("Palindrome invalid");
    }
    return 0;
}