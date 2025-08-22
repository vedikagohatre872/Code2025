#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWords(char *s) {
    int n = strlen(s);
    char *words[10000]; // store words
    int count = 0;

    // Step 1: Extract words
    char *token = strtok(s, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // Step 2: Print words in reverse order
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) printf(" ");
    }
}

int main() {
    char s[] = "   the   sky   is   blue   ";
    reverseWords(s);
    return 0;
}
