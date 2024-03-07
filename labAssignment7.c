#include <stdio.h>
#include <string.h>

#define SIZE1 9 // Size of the first array
#define SIZE2 9 // Size of the second array

void bubbleSort(int arr[], int n, int swapCount[], int original[]);
void selectionSort(int arr[], int n, int swapCount[], int original[]);
void printSwaps(int arr[], int original[], int swapCount[], int n);
int findIndex(int arr[], int n, int value);

int main() {
    int array1[SIZE1] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int originalArray1[SIZE1];
    int array2[SIZE2] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int originalArray2[SIZE2];
    int swapCount1[SIZE1] = { 0 };
    int swapCount2[SIZE2] = { 0 };

    // Copy the original arrays
    memcpy(originalArray1, array1, sizeof(array1));
    memcpy(originalArray2, array2, sizeof(array2));

    // Perform Bubble Sort on array1
    bubbleSort(array1, SIZE1, swapCount1, originalArray1);
    printf("Array1 Bubble Sort:\n");
    printSwaps(array1, originalArray1, swapCount1, SIZE1);

    // Reset array1 from originalArray1 for selection sort
    memcpy(array1, originalArray1, sizeof(array1));
    // Reset swap counts for selection sort
    memset(swapCount1, 0, sizeof(swapCount1));

    // Perform Bubble Sort on array2
    bubbleSort(array2, SIZE2, swapCount2, originalArray2);
    printf("Array2 Bubble Sort:\n");
    printSwaps(array2, originalArray2, swapCount2, SIZE2);

    // Reset array2 from originalArray2 for selection sort
    memcpy(array2, originalArray2, sizeof(array2));
    // Reset swap counts for selection sort
    memset(swapCount2, 0, sizeof(swapCount2));

    // Perform Selection Sort on array1
    selectionSort(array1, SIZE1, swapCount1, originalArray1);
    printf("Array1 Selection Sort:\n");
    printSwaps(array1, originalArray1, swapCount1, SIZE1);

    // Perform Selection Sort on array2
    selectionSort(array2, SIZE2, swapCount2, originalArray2);
    printf("Array2 Selection Sort:\n");
    printSwaps(array2, originalArray2, swapCount2, SIZE2);

    return 0;
}


void bubbleSort(int arr[], int n, int swapCount[], int original[]) {
    int i, j, temp, swapIdx1, swapIdx2;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapIdx1 = findIndex(original, n, arr[j]);
                swapIdx2 = findIndex(original, n, arr[j + 1]);
                if (swapIdx1 != -1) swapCount[swapIdx1]++;
                if (swapIdx2 != -1) swapCount[swapIdx2]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swapCount[], int original[]) {
    int i, j, min_idx, temp, swapIdxI, swapIdxMinIdx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Find the original indices of the elements being swapped.
            swapIdxI = findIndex(original, n, arr[i]);
            swapIdxMinIdx = findIndex(original, n, arr[min_idx]);

            // Swap the elements in the array.
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;

            // Increment swap counts for the original positions of the elements being swapped.
            if (swapIdxI != -1) swapCount[swapIdxI]++;
            if (swapIdxMinIdx != -1) swapCount[swapIdxMinIdx]++;
        }
    }
}

void printSwaps(int arr[], int original[], int swapCount[], int n) {
    for (int i = 0; i < n; i++) {
        // Find the swap count index of the current sorted element in the original array.
        int idx = findIndex(original, n, arr[i]);
        printf("%d: %d\n", arr[i], swapCount[idx]);
    }

    // Sum and print total swaps.
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps += swapCount[i];
    }
    printf("Total Swaps: %d\n", totalSwaps / 2);
}


int findIndex(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
