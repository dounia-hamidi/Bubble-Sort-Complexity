#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSortBasic(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

void bubbleSortOptimized(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;
    for (int i = 0; i < n; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
                swapped = 1;
            }
        }
        if (!swapped) break; // Exit early if no swaps
    }
}

void generateDatasets(int sorted[], int reverseSorted[], int random[], int size) {
    for (int i = 0; i < size; i++) {
        sorted[i] = i + 1;                  // Sorted dataset
        reverseSorted[i] = size - i;       // Reverse sorted dataset
        random[i] = rand() % size + 1;     // Random dataset
    }
}

void printResults(const char *datasetType, int size, int basicComparisons, int optimizedComparisons,
                  int basicSwaps, int optimizedSwaps, double basicTime, double optimizedTime) {
    printf("%-15s | %-5d | %-20d | %-22d | %-15d | %-20d | %-10.6f | %-10.6f\n",
           datasetType, size, basicComparisons, optimizedComparisons, basicSwaps, optimizedSwaps, basicTime, optimizedTime);
}

int main() {
    int sizes[] = {10, 100, 500};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    printf("Dataset Type    | Size  | Comparisons (Basic) | Comparisons (Optimized) | Swaps (Basic) | Swaps (Optimized) | Time (Basic) | Time (Optimized)\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

    for (int k = 0; k < numSizes; k++) {
        int size = sizes[k];
        int *sorted = (int *)malloc(size * sizeof(int));
        int *reverseSorted = (int *)malloc(size * sizeof(int));
        int *random = (int *)malloc(size * sizeof(int));
        int *temp = (int *)malloc(size * sizeof(int));

        generateDatasets(sorted, reverseSorted, random, size);

        // Test Sorted Dataset
        int basicComparisons, optimizedComparisons, basicSwaps, optimizedSwaps;
        double basicTime, optimizedTime;

        // Basic Bubble Sort
        for (int i = 0; i < size; i++) temp[i] = sorted[i];
        clock_t start = clock();
        bubbleSortBasic(temp, size, &basicComparisons, &basicSwaps);
        basicTime = (double)(clock() - start) / CLOCKS_PER_SEC;

        // Optimized Bubble Sort
        for (int i = 0; i < size; i++) temp[i] = sorted[i];
        start = clock();
        bubbleSortOptimized(temp, size, &optimizedComparisons, &optimizedSwaps);
        optimizedTime = (double)(clock() - start) / CLOCKS_PER_SEC;

        printResults("Sorted", size, basicComparisons, optimizedComparisons, basicSwaps, optimizedSwaps, basicTime, optimizedTime);

        // Test Reverse-Sorted Dataset
        for (int i = 0; i < size; i++) temp[i] = reverseSorted[i];
        start = clock();
        bubbleSortBasic(temp, size, &basicComparisons, &basicSwaps);
        basicTime = (double)(clock() - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < size; i++) temp[i] = reverseSorted[i];
        start = clock();
        bubbleSortOptimized(temp, size, &optimizedComparisons, &optimizedSwaps);
        optimizedTime = (double)(clock() - start) / CLOCKS_PER_SEC;

        printResults("Reverse-Sorted", size, basicComparisons, optimizedComparisons, basicSwaps, optimizedSwaps, basicTime, optimizedTime);

        // Test Random Dataset
        for (int i = 0; i < size; i++) temp[i] = random[i];
        start = clock();
        bubbleSortBasic(temp, size, &basicComparisons, &basicSwaps);
        basicTime = (double)(clock() - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < size; i++) temp[i] = random[i];
        start = clock();
        bubbleSortOptimized(temp, size, &optimizedComparisons, &optimizedSwaps);
        optimizedTime = (double)(clock() - start) / CLOCKS_PER_SEC;

        printResults("Random", size, basicComparisons, optimizedComparisons, basicSwaps, optimizedSwaps, basicTime, optimizedTime);

        free(sorted);
        free(reverseSorted);
        free(random);
        free(temp);
    }

    return 0;
}
