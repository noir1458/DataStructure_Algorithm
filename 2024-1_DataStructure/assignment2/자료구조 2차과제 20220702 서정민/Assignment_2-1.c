#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* Left, * Right;
}Node;

Node* Insert(Node* node, int data)
{
    if (node == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->Left = NULL;
        newNode->Right = NULL;

        return newNode;
    }
    else
    {
        // edit1
        /*
        TODO: Fill the conditions in Insert function
        */
        // 삽입할 데이터가 현재 노드의 데이터보다 작다면
        // 왼쪽으로 가서 다시 삽입 연산
        if (data < node->data)
        {
            node->Left = Insert(node->Left, data);
            return node;
        }
        /*
        TODO: Fill the conditions in Insert function
        */
        // 삽입할 데이터가 현재 노드의 데이터보다 크다면
        // 우측으로 가서 다시 삽입연산
        else if (data > node->data)
        {
            node->Right = Insert(node->Right, data);
            return node;
        }
        else
        {
            return node;
        }

    }
}


int Search(Node* node, int data)
{
    if (node == NULL) {
        printf("No Node %d ", data);
        return 0;
    }

    if (node->data == data)
    {
        return node->data;
    }
    else
    {
        /*
        TODO: Implement the Search function conditions
        */
        // 찾는 데이터보다 지금 노드의 데이터가 작거나 같다면
        // 왼쪽으로 가야 한다
        if (node->data > data) {
            return Search(node->Left, data);
        }
        else {
            return Search(node->Right, data);
        }

    }
}

Node* Delete(Node* node, int data)
{
    if (node == NULL) return NULL;

    if (node->data == data)
    {
        Node* deleteNode = node;
        /*
        TODO: Implement the Delete function conditions
        */
        // 1. 자식이 없는 노드의 경우 - 그냥 지우자
        if (node->Left == NULL && node->Right == NULL) {
            free(deleteNode);
            return NULL;
        }
        // 2. 자식이 하나만 있는 노드의 경우, 크기 판단해서 그 위에 붙이기
        else if (node->Left == NULL || node->Right == NULL) {
            Node* tmp = NULL;
            if (node->Left != NULL) {
                // 왼쪽노드가 있을경우
                tmp = node->Left;
            }
            else {
                //오른쪽 노드가 있을 경우
                tmp = node->Right;
            }
            free(deleteNode);
            return tmp; //그 자식노드를 대신 붙인다
        }
        // 3. 3. 자식이 두개 다 있는 노드를 지울때 - 오른쪽 자식중 가장 작은걸 왼쪽 자식으로
        else {
            // 오른쪽 자식중 가장 작은 값 찾기
            Node* parent = node;
            Node* right_min = node->Right;
            while (right_min->Left != NULL) {
                parent = right_min;
                right_min = right_min->Left;
            }
            node->data = right_min->data;

            if (parent != node) {
                parent->Left = right_min->Right;
            }
            else {
                parent->Right = right_min->Right;
            }
            free(right_min);
        }
        return node;
    }
    else
    {
        /*
        TODO: Implement the delete function traversal
        일단 노드까지 찾아가는게 먼저 그 다음에 경우를 판단하자
        */
        if (node->data > data) {
            node->Left = Delete(node->Left, data);
        }
        else if (node->data < data) {
            node->Right = Delete(node->Right, data);
        }

        return node;
    }
}


// BST Print function 

/* Do not Modify on Submition */


int getHeight(Node* node) {
    if (node == NULL) return 0;
    int leftHeight = getHeight(node->Left);
    int rightHeight = getHeight(node->Right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(Node* node, int level, int currentLevel, int indentSpace) {
    if (node == NULL) {
        if (currentLevel == level) {
            for (int i = 0; i < indentSpace; i++) printf(" ");
        }
        return;
    }
    if (level == currentLevel) {
        printf("%*s%d", indentSpace, "", node->data);
    }
    else {
        printLevel(node->Left, level, currentLevel + 1, indentSpace);
        printLevel(node->Right, level, currentLevel + 1, indentSpace);
    }
}

void ShowInOrder(Node* root) {
    int height = getHeight(root);
    int indentSpace = 2;
    for (int i = 0; i < height; i++) {
        printLevel(root, i, 0, indentSpace * (height - i));
        printf("\n");
    }
    printf("\n");
}

// Main Function

/* Do not Modify on Submition */

int main()
{
    Node* root = NULL;

    //INSERT
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 32);
    root = Insert(root, 4);
    root = Insert(root, 13);
    root = Insert(root, 25);
    root = Insert(root, 55);

    //SHOW
    ShowInOrder(root);
    /*
       20
    10    32
  4  13  25  55
    */

    //SEARCH
    printf("Node: %d\n", Search(root, 12));
    /*
    No Node 12 Node: 0
    */
    //SEARCH
    printf("Node %d\n", Search(root, 13));
    /*
    Node: 13
    */

    //DELETE
    root = Delete(root, 32);

    ShowInOrder(root);
    /*
       20
    10    55
  4  13  25
    */
    getchar();
}
