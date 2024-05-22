#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        printf("Inserting %d as the left child of %d\n", key, root->key);
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        printf("Inserting %d as the right child of %d\n", key, root->key);
        root->right = insert(root->right, key);
    }

    return root;
}

int minValueNode(TreeNode* node);
TreeNode* delete(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = delete(root->left, key);
    } else if (key > root->key) {
        root->right = delete(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        root->key = minValueNode(root->right);
        root->right = delete(root->right, root->key);
    }
    return root;
}

int minValueNode(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node->key;
}

void inorderTraversalRecursive(TreeNode* root) {
    if (root != NULL) {
        inorderTraversalRecursive(root->left);
        printf("%d ", root->key);
        inorderTraversalRecursive(root->right);
    }
}

void inorderTraversalIterative(TreeNode* root) {
    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->key);

        current = current->right;
    }
}

void preorderTraversalRecursive(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }
}

void preorderTraversalIterative(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        TreeNode* current = stack[top--];
        printf("%d ", current->key);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

void postorderTraversalRecursive(TreeNode* root) {
    if (root != NULL) {
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        printf("%d ", root->key);
    }
}

void postorderTraversalIterative(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    TreeNode* stack1[100];
    TreeNode* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) {
        TreeNode* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->key);
    }
}

int main() {
    TreeNode* root = NULL;
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal using Recursion \n");
        printf("4. Preorder Traversal using Recursion\n");
        printf("5. Postorder Traversal using Recursion\n");
        printf("6. Inorder Traversal using Stack \n");
        printf("7. Preorder Traversal using Stack\n");
        printf("8. Postorder Traversal using Stack\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversalRecursive(root);
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorderTraversalRecursive(root);
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorderTraversalRecursive(root);
                break;
            case 6:
                printf("Inorder Traversal: ");
                inorderTraversalIterative(root);
                break;
            case 7:
                printf("Preorder Traversal: ");
                preorderTraversalIterative(root);
                break;
            case 8:
                printf("Postorder Traversal: ");
                postorderTraversalIterative(root);
                break;

            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 9);

    return 0;
}
