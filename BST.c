#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
int data;
struct Node* left;
struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
if (root == NULL) {

return createNode(data);
}

if (data < root->data) {
root->left = insert(root->left, data);
} else if (data > root->data) {
root->right = insert(root->right, data);
}

return root;
}

// Function for pre-order traversal
void preorderTraversal(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);
}
}

// Function for in-order traversal
void inorderTraversal(struct Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}

// Function for post-order traversal
void postorderTraversal(struct Node* root) {
if (root != NULL) {
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d ", root->data);
}
}

// Function to search for an element in the BST
struct Node* search(struct Node* root, int key) {
if (root == NULL || root->data == key) {
return root;
}

if (key < root->data) {
return search(root->left, key);
}

return search(root->right, key);
}

// Function to find the smallest element in the BST
struct Node* findMin(struct Node* root) {
while (root->left != NULL) {
root = root->left;
}
return root;
}

// Function to find the largest element in the BST
struct Node* findMax(struct Node* root) {
while (root->right != NULL) {
root = root->right;
}
return root;
}

// Function to find the height of the BST
int findHeight(struct Node* root) {
if (root == NULL) {
return -1;
}

int leftHeight = findHeight(root->left);
int rightHeight = findHeight(root->right);

return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
struct Node* root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);

printf("Pre-order traversal: ");
preorderTraversal(root);
printf("\n");

printf("In-order traversal: ");
inorderTraversal(root);
printf("\n");

printf("Post-order traversal: ");
postorderTraversal(root);
printf("\n");

int searchValue = 40;
struct Node* result = search(root, searchValue);
if (result != NULL) {
printf("%d found in the BST.\n", searchValue);
} else {
printf("%d not found in the BST.\n", searchValue);
}

struct Node* smallest = findMin(root);
struct Node* largest = findMax(root);
printf("Smallest element: %d\n", smallest->data);
printf("Largest element: %d\n", largest->data);

int height = findHeight(root);
printf("Height of the BST: %d\n", height);

return 0;
}
