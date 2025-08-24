#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to insert an element in the BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = val;
        root->left = root->right = NULL;
        printf("%d inserted into the BST",val);
    } else if (val < root->data) {
        root->left = insert(root->left, val);
        if (root->left && root->left->data == val) {
            printf(" as the left child of %d.",root->data);
        }
    } else if (val > root->data) {
        root->right = insert(root->right, val);
        if (root->right && root->right->data == val) {
            printf(" as the right child of %d.\n",root->data);
        }
    } else {
        printf("%d already exists, cannot insert in Binary Search Tree.\n", val);
    }
    return root;
}

// Function to delete an element in the BST
struct Node* delete(struct Node* root, int val) {
    if (root == NULL) {
        printf("Element not found in the tree.\n");
        return root;
    }

    if (val < root->data) {
        root->left = delete(root->left, val);
    } else if (val > root->data) {
        root->right = delete(root->right, val);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("%d deleted from the BST.\n", val);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("%d deleted from the BST.\n", val);
            return temp;
        }

        // Node with two children
        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}



// Function to display BST using in-order traversal
void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n\nBinary Search Tree Operations:\n");
        printf("1. Insert an element in BST\n");
        printf("2. Delete an element in BST\n");
        printf("3. Display BST (In-order traversal)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("BST (In-order traversal): ");
                display(root);
                printf("\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}