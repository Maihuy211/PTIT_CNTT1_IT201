#include <stdio.h>
int main() {
    int n = 5;
    int arr[] = {5, 3, 6, 2, 1};
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep : ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
// do phuc tap O (n^2)
