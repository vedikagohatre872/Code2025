#include <stdio.h>
#include <stdlib.h>

// Structure to hold subarray indices
typedef struct {
    int start;
    int end;
} Subarray;

// Function to find all subarrays with zero sum
Subarray* findZeroSumSubarrays(int arr[], int n, int* returnSize) {
    int prefixSum = 0;
    int capacity = 100; // initial size
    *returnSize = 0;
    
    // Allocate memory for result
    Subarray* result = (Subarray*)malloc(capacity * sizeof(Subarray));

    // Brute force using prefix sum
    for (int i = 0; i < n; i++) {
        prefixSum = 0;
        for (int j = i; j < n; j++) {
            prefixSum += arr[j];
            if (prefixSum == 0) {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (Subarray*)realloc(result, capacity * sizeof(Subarray));
                }
                result[*returnSize].start = i;
                result[*returnSize].end = j;
                (*returnSize)++;
            }
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int returnSize = 0;

    Subarray* result = findZeroSumSubarrays(arr, n, &returnSize);

    if (returnSize == 0) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < returnSize; i++) {
            printf("(%d, %d)", result[i].start, result[i].end);
            if (i < returnSize - 1) printf(", ");
        }
        printf("]\n");
    }

    free(result);
    return 0;
}
