#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 구조체 정의
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 이진 트리 노드 생성 함수
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 트리 좌우를 뒤집는 함수
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL; // 빈 트리인 경우

    // 좌우 자식 노드를 재귀적으로 뒤집음
    struct TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

// 이진 트리 출력 함수 (전위 순회)
void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // 이진 트리 생성
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 원본 트리 출력
    printf("Original tree: ");
    printTree(root);
    printf("\n");

    // 좌우 뒤집은 이진 트리 생성
    struct TreeNode* invertedRoot = invertTree(root);

    // 뒤집힌 트리 출력
    printf("Inverted tree: ");
    printTree(invertedRoot);
    printf("\n");

    return 0;
}
