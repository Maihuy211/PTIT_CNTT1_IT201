#include <stdio.h>
int sumArray(int arr[],int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n-1] + sumArray(arr,n - 1);
}
int main() {
    int n, arr[100];
    printf("nhap so luong mang: ");
    scanf("%d", &n);
    printf("nhap cac phan tu cho mang\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("mang la: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]= %d\n", i, arr[i]);
    }
    printf("%d",sumArray(arr,n));
}