#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp, swaps;
    for (i = 0; i < size - 1; i++) {
        swaps = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
        printf("\nSwaps at index %d: %d", i, swaps);
    }
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Array:\n\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size);

    printf("\n\nSorted Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
