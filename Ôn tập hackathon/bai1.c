#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    int id;
    char title[100];
    int credit;
}Course;

typedef struct SLL {
    Course data;
    struct SLL* next ;
}SLL;

SLL* createSLL(Course course){
    SLL* node = (SLL*)malloc(sizeof(SLL));
    node->data = course;
    node->next = NULL;

   return node;
}

int getLength(SLL* head) {
    int count = 0;
    SLL* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printCourse(SLL *head){
    if(head == NULL){
        printf("dang sach rong\n");
        return;
    }
    SLL* current = head;
    while(current != NULL){
        printf("\n");
        printf("id : %d\n",current->data.id);
        printf("title: %s\n",current->data.title);
        printf("credit : %d\n",current->data.credit);
        current = current->next;
    }
}
SLL* insertCourse(SLL* head, Course course, int pos){
    int len = getLength(head);
    if (pos < 0 || pos > len) {
        printf("vi tri ko hop le\n");
        return head;
    }
    SLL* newCourse = createSLL(course);
    if(pos == 0){
        newCourse->next = head;
        return newCourse;
    }
    SLL* current = head;
    for(int i = 0 ; i < pos - 1 ; i++){
        current = current->next;
    }
    newCourse->next = current->next;
    current->next= newCourse;

    return head;
}
SLL* deleteCourse(SLL* head, int id){
    if(head == NULL){
        return NULL;
    }
    if(head->data.id == id){
        SLL* temp = head;
        head = head->next;
        free(temp);
        printf("Xoa thanh cong");
        return head;
    }
    SLL *current = head;
    while (current->next != NULL && current->next->data.id != id) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Khong tim thay khoa hoc");
        return head;
    }
    SLL* temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Xoa thanh cong");
    return head;
}
void updateCourse(SLL* head, int id){
    if(head == NULL){
        printf("Danh sach rong");
        return;
    }
    SLL *current = head;
    while (current != NULL && current->data.id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Khong tim thay khoa hoc");
        return;
    }
    printf("Nhap ten khoa hoc moi : ");
    fgets(current->data.title , 100 , stdin);
    current->data.title[strcspn(current->data.title,"\n")] = '\0';
    printf("Nhap so tin chi moi : ");
    scanf("%d",&current->data.credit);

    getchar();

    printf("Cap nhat thong tin thanh cong");
}
void sort(SLL* head){
    if(head == NULL){
        printf("Danh sach rong");
        return;
    }
    SLL* i = head;
    SLL* j = NULL;
    Course temp;
    while(i != NULL){
        j = i->next;
        while(j != NULL){
            if (i->data.credit > j->data.credit){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i=i->next;
    }
}
void search(SLL* head, char check[100]){
    if(head == NULL){
        printf("Danh sach rong");
        return;
    }
    int flag = 0; 
    SLL* current = head ;
    while(current != NULL){
        if(strstr(current->data.title, check) != NULL){
            printf("id : %d\n",current->data.id);
            printf("title: %s\n",current->data.title);
            printf("credit : %d\n",current->data.credit);
            flag = 1;
        }
        current = current->next;
    }
    if (!flag) {
        printf("Khong tim thay khoa hoc\n");
    }
}

typedef struct DLL {
    Course data;
    struct SLL* next ;
    struct DLL* prev ;
}DLL;

DLL* createDLL(Course course){
    DLL* node = (DLL*)malloc(sizeof(DLL));
    node->data = course;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// DLL* insertComplete(DLL* completedList, Course course) {
//     DLL* newNode = createDLL(course);
//     newNode->next = completedList;
//     if (completedList != NULL) {
//         completedList->prev = newNode;
//     }
//     return newNode;
// }

// DLL* complete(SLL* head , DLL* completedList, int id){
//     if (head == NULL) {
//         printf("Danh sach rong\n");
//         return head;
//     }
//     SLL* current = head;
//     SLL* prev = NULL;
//     while (current != NULL && current->data.id != id) {
//         prev = current;
//         current = current->next;
//     }
//     if (current == NULL) {
//         printf("Khong tim thay");
//         return head;
//     }
//     if (prev == NULL){
//         head = current->next;
//     }else{
//         prev->next = current->next;
//     } 
//     free(current);
//     printf("Danh dau hoan thanh khoa hoc thanh cong");
//     return head;
// }
int main(){
    int choice;
    SLL* head = NULL;
    SLL* node1 = NULL;
    Course course;
    int n;
    int pos;
    int id;
    char check[100];
    do{
        printf("\n");
        printf("\n1. Them khoa hoc\n");
        printf("2. Hien thi danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhat thong tin khoa hoc\n");
        printf("5. Danh khoa hoc hoan thanh\n");
        printf("6. Sap xep so tin chi\n");
        printf("7. Tim kiem khoa hoc theo ten\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("nhap so luong danh sach mon hoc muon them: ");
                scanf("%d",&n);
                for(int i = 1 ; i <= n ; i++){
                    printf("\n");
                    printf("Nhap id khoa hoc: ");
                    scanf("%d",&course.id);
                    getchar();
                    printf("Nhap ten khoa hoc: ");
                    fgets(course.title , 100 , stdin);
                    course.title[strcspn(course.title,"\n")] = '\0';
                    printf("Nhap so tin chi: ");
                    scanf("%d",&course.credit);
                    getchar();
                    printf("nhap vi tri muon them: ");
                    scanf("%d",&pos);
                    getchar();
                    head = insertCourse(head,course,pos-1);
                }
                printf("\nthem khoa hoc thanh cong\n");
                break;
            case 2:
                printf("\nDanh sach khoa hoc la: \n");
                printCourse(head);
                break;
            case 3:
                printf("Nhap id khoa hoc muon xoa: ");
                scanf("%d", &id);
                getchar();
                head = deleteCourse(head, id);
                break;
            case 4:
                printf("Nhap id khoa hoc muon cap nhat: ");
                scanf("%d", &id);
                getchar();
                updateCourse(head,id);
                break;
            case 5:
                // printf("Nhap id khoa hoc hoan thanh: ");
                // scanf("%d", &id); 
                // getchar();
                // Course completeList;
                // head = complete(head,&completeList,id);
                break;
            case 6:
                sort(head);
                break;
            case 7:
                printf("Nhap ten khoa hoc can tim kiem: ");
                fgets(check, 100 , stdin);
                check[strcspn(check,"\n")] = '\0';
                search(head,check);
                break;
            case 8:
                printf("\nThoat chuong trinh\n");
                break;
            default:
                printf("\nLua chon khong hop le\n");
        }
    }while(choice != 8);
    return 0;
}
