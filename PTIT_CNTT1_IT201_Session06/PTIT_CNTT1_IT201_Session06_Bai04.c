#include <stdio.h>
void TowerOfHanoi(int n, char from, char to, char temp){
    if(n==1){
        printf("Dia 1 di chuyen tu %c sang %c\n",from,to);
        return;
    }
    TowerOfHanoi(n-1,from,temp,to);
    printf("Dia %d di chuyen tu %c sang %c\n",n,from,to);
    TowerOfHanoi(n-1,to,from,temp);
}
int main(){
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    if(n<=0){
        printf("khong hop le");
    }else{
        TowerOfHanoi(n,'A','C','B');
    }
    return 0;
}