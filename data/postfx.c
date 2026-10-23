#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

// Stack for tree nodes
struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Construct expression tree from postfix expression
struct Node* constructTree(char postfix[]) {
    int i;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isalnum(ch)) {
            push(createNode(ch));
        }
        else if (isOperator(ch)) {
            struct Node* node = createNode(ch);

            node->right = pop();
            node->left = pop();

            push(node);
        }
    }

    return pop();
}

// Postorder traversal gives postfix expression
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = constructTree(postfix);

    printf("Postfix expression: ");
    postorder(root);

    return 0;
}

