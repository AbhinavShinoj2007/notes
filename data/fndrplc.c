#include <stdio.h>
#include <string.h>

#define MAX 1000

void findAndReplace(char text[], char find[], char replace[]) {
    char result[MAX];
    char *pos;
    int findLen = strlen(find);
    int replaceLen = strlen(replace);

    result[0] = '\0';

    while ((pos = strstr(text, find)) != NULL) {

        // Copy text before the found word
        strncat(result, text, pos - text);

        // Add replacement word
        strcat(result, replace);

        // Move past the found word
        text = pos + findLen;
    }

    // Add remaining text
    strcat(result, text);

    strcpy(text, result);

    printf("\nText after replacement:\n%s\n", text);
}

int main() {
    char text[MAX];
    char find[100];
    char replace[100];

    printf("Enter the text:\n");
    fgets(text, MAX, stdin);

    // Remove newline
    text[strcspn(text, "\n")] = '\0';

    printf("Enter word to find: ");
    scanf("%s", find);

    printf("Enter replacement word: ");
    scanf("%s", replace);

    findAndReplace(text, find, replace);

    return 0;
}

