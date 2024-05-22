#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countNodes(TreeNode* root) {
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findHeight(TreeNode* root) {
    if (root == NULL)
        return -1;
    else
        return 1 + max(findHeight(root->left), findHeight(root->right));
}

void mirrorImage(TreeNode* root) {
    if (root == NULL)
        return;
    
    mirrorImage(root->left);
    mirrorImage(root->right);

    // Swap left and right subtrees
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    TreeNode* root = NULL;

    int choice;
    do {
        printf("\nTree Functions\n");
        printf("1. Insert node\n");
        printf("2. Count nodes\n");
        printf("3. Find height\n");
        printf("4. Mirror Image\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int data;
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    printf("Node inserted successfully!\n");
                }
                break;
            case 2:
                printf("Number of nodes in the tree: %d\n", countNodes(root));
                break;
            case 3:
                printf("Height of the tree: %d\n", findHeight(root));
                break;
            case 4:
                printf("Inorder traversal before mirror image: ");
                inorderTraversal(root);
                printf("\n");

                mirrorImage(root);

                printf("Inorder traversal after mirror image: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
