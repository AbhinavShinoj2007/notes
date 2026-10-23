#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *current = NULL;

void visit(char url[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);

    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        struct Node *temp = current->next;

        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }

        current->next = newNode;
    }

    current = newNode;

    printf("Visited: %s\n", current->url);
}

void back() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page.\n");
        return;
    }

    current = current->prev;
    printf("Back: %s\n", current->url);
}

void forward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page.\n");
        return;
    }

    current = current->next;
    printf("Forward: %s\n", current->url);
}

void displayCurrent() {
    if (current == NULL)
        printf("No page visited.\n");
    else
        printf("Current page: %s\n", current->url);
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser History ---\n");
        printf("1. Visit webpage\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Current page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;

            case 2:
                back();
                break;

            case 3:
                forward();
                break;

            case 4:
                displayCurrent();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
