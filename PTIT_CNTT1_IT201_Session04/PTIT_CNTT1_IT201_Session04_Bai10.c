#include <stdio.h>
#include <string.h>
struct Student{
    int id;
    char name[50];
    int age;
};
int main() {
    struct  Student sv[50];
    int n ;
    printf("nhap so sinh vien: ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        sv[i].id=i+1;
        printf("nhap ten thu %d: ",i+1);
        scanf("%s",sv[i].name);
        printf("nhap tuoi thu %d: ",i+1);
        scanf("%d",&sv[i].age);
    }
    char x[50];
    printf("nhap name can tim: ");
    scanf("%s",&x);
    int found = 0;
    for(int i = 0 ; i < n ; i++){
        if(strstr(sv[i].name,x)!=NULL){
            printf("id : %d , name : %s , age : %d\n",sv[i].id,sv[i].name,sv[i].age);
            found = 1;
        }
    }
    if(!found) printf("ko co sinh vien");
    return 0;
}