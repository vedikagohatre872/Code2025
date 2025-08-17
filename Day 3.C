#include <stdio.h>

int findDuplicate(int arr[], int n) {
    // Step 1: Detect cycle
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Step 2: Find entrance to cycle (duplicate number)
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int arr[] = {3, 1, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int duplicate = findDuplicate(arr, size);
    printf("Duplicate number: %d\n", duplicate);

    return 0;
}
