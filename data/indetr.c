#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Search for a node
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// Find minimum value node
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct Node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder: Root -> Left -> Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left -> Right -> Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    struct Node* result;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Value inserted successfully.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) != NULL) {
                    root = deleteNode(root, value);
                    printf("Value deleted successfully.\n");
                }
                else {
                    printf("Value not found.\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result != NULL) {
                    printf("%d found in the BST.\n", value);
                }
                else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

