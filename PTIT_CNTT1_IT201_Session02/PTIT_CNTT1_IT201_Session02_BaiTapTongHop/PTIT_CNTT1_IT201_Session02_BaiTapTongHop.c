#include <stdio.h>
#include <stdlib.h> 
int *insertToArray(int *numbers, int *size, int value);
void printArray(int *numbers, int size);
int *delFromArray(int *numbers, int *size, int delPos);

int main(void){
    int choice;
    int *numbers = NULL;
    int size = 0;
    int value, delPos;
    do {
        printf("\n\tMenu\n");
        printf("1. Them phan tu\n");
        printf("2. Hien thi phan tu\n");
        printf("3. Xoa phan tu\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                numbers = insertToArray(numbers, &size, value);
                break;
            case 2:
                printf("Cac phan tu trong mang\n");
                printArray(numbers, size);
                break;
            case 3:
                printf("Nhap phan tu can xoa", size - 1);
                scanf("%d", &delPos);
                numbers = delFromArray(numbers, &size, delPos);
                break;
            case 4:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon ko hop le\n");
        }
    } while(choice != 4);
    free(numbers); 
    return 0;
}
int *insertToArray(int *numbers, int *size, int value){
    numbers = (int*)realloc(numbers, (*size + 1) * sizeof(int));
    numbers[*size] = value;
    (*size)++;
    return numbers;
}
void printArray(int *numbers, int size){
    if (size == 0) {
        printf("M?ng r?ng.\n");
        return;
    }
    for (int i = 0; i < size; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
int *delFromArray(int *numbers, int *size, int delPos){
    if (delPos < 0 || delPos >= *size){
        printf("vi tri ko hop le\n");
        return numbers;
    }
    for (int i = delPos; i < (*size - 1); i++){
        numbers[i] = numbers[i + 1];
    }
    (*size)--;
    numbers = (int*)realloc(numbers, (*size) * sizeof(int));
    return numbers;
}

