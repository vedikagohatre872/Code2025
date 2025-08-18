#include <stdio.h>
#include <math.h>

// Utility function to get next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int m, int n) {
    int gap = m + n;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        int i, j;

        // Compare elements in first array
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap]) {
                int temp = arr1[i];
                arr1[i] = arr1[i + gap];
                arr1[i + gap] = temp;
            }
        }

        // Compare elements between arr1 and arr2
        for (j = (gap > m ? gap - m : 0); i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j]) {
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            }
        }

        // Compare elements in second array
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap]) {
                    int temp = arr2[j];
                    arr2[j] = arr2[j + gap];
                    arr2[j + gap] = temp;
                }
            }
        }
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    merge(arr1, arr2, m, n);

    printf("arr1: ");
    for (int i = 0; i < m; i++) printf("%d ", arr1[i]);
    printf("\narr2: ");
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);

    return 0;
}
