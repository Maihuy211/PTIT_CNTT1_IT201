#include <stdio.h>
#include <string.h>

void sortString(char str[], int n){
   for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(str[j]>str[j+1]){
                int temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}
int main(){
    char str[100];
    printf("nhap mot chuoi ki tu bat ki: ");
    fgets(str, sizeof(str), stdin);
    int n = strlen(str);
    if(n == 0){
        printf("chuoi ko hop le: ");
    }else{
        printf("%s",str);
        sortString(str,n);
        printf("%s",str);
    }
    return 0;
}