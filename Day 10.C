#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to sort characters in a string
void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to group anagrams
void groupAnagrams(char strs[][20], int n) {
    int visited[n];
    memset(visited, 0, sizeof(visited));  // mark all as unvisited
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;  // already grouped
        
        // Print start of a group
        printf("[");
        printf("\"%s\"", strs[i]);
        visited[i] = 1;
        
        // Create sorted key for current string
        char key1[20];
        strcpy(key1, strs[i]);
        sortString(key1);
        
        for (int j = i+1; j < n; j++) {
            if (!visited[j]) {
                char key2[20];
                strcpy(key2, strs[j]);
                sortString(key2);
                
                if (strcmp(key1, key2) == 0) {
                    printf(", \"%s\"", strs[j]);
                    visited[j] = 1;
                }
            }
        }
        printf("]\n");
    }
}

int main() {
    char strs[][20] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(strs) / sizeof(strs[0]);
    
    printf("Grouped Anagrams:\n");
    groupAnagrams(strs, n);
    
    return 0;
}
