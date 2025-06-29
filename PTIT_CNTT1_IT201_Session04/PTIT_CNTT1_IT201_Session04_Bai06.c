#include <stdio.h>
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
        printf("nhap ten: ");
        scanf("%s",sv[i].name);
        printf("nhap tuoi: ");
        scanf("%d",&sv[i].age);
    }
    int id;
    printf("nhap id can tim: ");
    scanf("%d",&id);
    int found = 0;
    for(int i = 0 ; i < n ; i++){
        if(sv[i].id == id){
            printf("id : %d , name : %s , age : %d",sv[i].id,sv[i].name,sv[i].age);
            found = 1;
            break;
        }
    }
    if(!found) printf("ko co sinh vien");
    return 0;
}