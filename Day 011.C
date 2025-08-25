#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to swap characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str); // One permutation found
    } else {
        int used[256] = {0}; // To avoid duplicate chars at the same level
        for (int i = l; i <= r; i++) {
            if (!used[(int)str[i]]) {  // Skip if char already used
                used[(int)str[i]] = 1;

                swap(&str[l], &str[i]);
                permute(str, l + 1, r);
                swap(&str[l], &str[i]); // backtrack
            }
        }
    }
}

int main() {
    char str[20];
    printf("Enter string: ");
    scanf("%s", str);

    int n = strlen(str);
    permute(str, 0, n - 1);

    return 0;
}
