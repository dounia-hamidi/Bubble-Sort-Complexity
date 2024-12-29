#include <stdio.h>

// Function to perform basic Bubble Sort without optimizations
void bubbleSortBasic(int arr[], int n) {
    // Outer loop for passes
    for (int i = 0; i < n; i++) {
        // Inner loop for comparing and swapping adjacent elements
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test array
    int arr[] = {5, 3, 8, 4, 25, 3, 8, 4, 25, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);  // Get the number of elements in the array

    // Print original array
    printf("Original array: ");
    printArray(arr, n);

    // Perform bubble sort
    bubbleSortBasic(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

