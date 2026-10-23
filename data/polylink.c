#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* addterm(struct Node* head, int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node *p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;

    return head;
}

void display(struct Node* head) {
    struct Node *p = head;

    printf("The result:\n");

    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);

        p = p->next;

        if (p != NULL) {
            printf(" + ");
        }
    }

    printf("\n");
}

struct Node* add(struct Node *p1, struct Node *p2, int n, int m) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {

        if (p1->exp == p2->exp) {
            result = addterm(result,
                             p1->coeff + p2->coeff,
                             p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }

        else if (p1->exp > p2->exp) {
            result = addterm(result,
                             p1->coeff,
                             p1->exp);

            p1 = p1->next;
        }

        else {
            result = addterm(result,
                             p2->coeff,
                             p2->exp);

            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = addterm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = addterm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node *T1 = NULL;
    struct Node *T2 = NULL;
    struct Node *result = NULL;

    int c, e, i, n, m;

    printf("Enter how many terms you need to enter in the first polynomial:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the coefficient:\n");
        scanf("%d", &c);

        printf("Enter the exponent:\n");
        scanf("%d", &e);

        T1 = addterm(T1, c, e);
        }

    printf("Enter how many terms you need to enter in the second polynomial:\n");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the coefficient:\n");
        scanf("%d", &c);

        printf("Enter the exponent:\n");
        scanf("%d", &e);

        T2 = addterm(T2, c, e);
    }

    printf("\nEntered polynomial 1:\n");
    display(T1);

    printf("\nEntered polynomial 2:\n");
    display(T2);

    result = add(T1, T2, n, m);

    printf("\nAdded polynomial:\n");
    display(result);

    return 0;
}
