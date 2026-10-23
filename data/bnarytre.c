#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
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

// Search for a value
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Find the minimum value node
struct Node* findMin(struct Node* root) {
    struct Node* current = root;

    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    struct Node* temp;

    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node has no left child
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        // Node has no right child
        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;

    while (1) {
        printf("\n\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result != NULL)
                    printf("%d found in the BST.\n", value);
                else
                    printf("%d not found in the BST.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) != NULL) {
                    root = deleteNode(root, value);
                    printf("%d deleted successfully.\n", value);
                }
                else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 4:
                printf("BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

