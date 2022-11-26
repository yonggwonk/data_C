#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int value;
    struct node* llink;
    struct node* rlink;      //linked 리스트 구조체 정의
}node;

typedef struct Tree {
    node* root;
}Tree;      //트리 구조체 정의

Tree* newTree() {
    Tree* nullspace = NULL;
    nullspace = (Tree*)malloc(sizeof(Tree));
    if (nullspace != NULL)
        nullspace->root = NULL;
    return nullspace;
}      //새로운 이진 탐색 트리 생성, tree를 저장할 메모리를 동적할당해줌

int insertnode(Tree* tree, node element) {   //새로운 값을 트리에 삽입
    node* parentnode = NULL;
    int ret = TRUE;

    if (tree == NULL) {
        int ret = FALSE;
        return ret;
    }      //tree가 비어있을 시 거짓을 반환
    parentnode = tree->root;
    while (parentnode != NULL) {
        if (element.value == parentnode->value) {
            printf("중복된 값 입니다.\n");   //기존에 존재하던 값과 같을 경우 거짓 반환
            ret = FALSE;
            return ret;
        }
        else if (element.value < parentnode->value) { //입력받은 값이 현재 노드보다 작을 때
            if (parentnode->llink == NULL) {      //삽입할 공간이 존재한다면
                break;
            }
            else {
                parentnode = parentnode->llink;   //없다면 왼족 서브트리로 공간 할당 후 저장
            }
        }
        else {
            parentnode = parentnode->rlink;  //입력받은 값이 현재 노드보다 클 때 오른쪽 서브트리로 이동
        }
    }
    node* newnode = NULL;
    newnode = (node*)malloc(sizeof(node));
    if (newnode != NULL) {
        *newnode = element;
        newnode->llink = NULL;
        newnode->rlink = NULL;

        if (parentnode == NULL) {
            tree->root = newnode;   //부모 노드가 없을 시 새로운 루트로 지정
        }
        else {
            if (newnode->value < parentnode->value) {   //부모 노드와 비교하여 더 작으면
                parentnode->llink = newnode;   //왼쪽 가지로 저장
            }
            else {
                parentnode->rlink = newnode;   //오른쪽 가지로 저장
            }
        }
        ret = TRUE;
    }
    return ret;
}

int deletenode(Tree* tree, int value) {      //삭제할 값을 입력받아 삭제
    int ret = TRUE;
    node* deletenode;
    node* parentnode;
    node* lchild;
    node* rchild;
    node* childnode;

    if (tree == NULL) {      //삭제할 노드를 탐색하는 코드
        ret = FALSE;
        return ret;
    }
    parentnode = NULL;
    deletenode = tree->root;
    while (deletenode != NULL) {
        if (value == deletenode->value) {      //삭제하려는 값이 입력받은 값과 같다면 바로 삭제하러 이동
            break;
        }
        parentnode = deletenode;
        if (value < deletenode->value) {
            deletenode = deletenode->llink;
        }
        else {
            deletenode = deletenode->rlink;      //값의 크기를 비교하며 자식 노드를 이동하며 탐색
        }
    }
    if (deletenode == NULL) {
        printf("해당 값이 트리에 존재하지 않습니다.\n");
        ret = FALSE;
        return ret;
    }

    //삭제 후 부모 노드와 link 다시 할당
    if (deletenode->llink == NULL && deletenode->rlink == NULL) {      //삭제할 노드의 자식 노드가 없을 때
        if (parentnode != NULL) {
            if (parentnode->llink == deletenode) {
                parentnode->llink = NULL;
            }
            else {
                parentnode->rlink = NULL;  //부모노드의 r,l탐색 후 NULL값을 대입
            }
        }
        else {
            tree->root = NULL;   //부모노드가 비었다면 root에 null저장
        }
    }
    else if (deletenode->llink != NULL && deletenode->rlink != NULL) {   //삭제할 노드의 자식 노드가 2개
        lchild = deletenode;
        rchild = deletenode->llink;

        while (rchild->rlink != NULL) {      //왼쪽 자식 트리의 최댓값
            lchild = rchild;
            rchild = rchild->rlink;
        }
        lchild->rlink = rchild->llink;
        rchild->llink = deletenode->llink;
        rchild->rlink = deletenode->rlink;

        if (parentnode != NULL) {
            if (parentnode->llink = deletenode) {
                parentnode->llink = rchild;
            }
            else {
                parentnode->rlink = rchild;      //부모노드가 있을땐 삭제할 노드가 llink라면, llink로 rchild 대입
            }
        }
        else {
            tree->root = rchild;      //없을 땐 루트로 바로 대입
        }
    }
    else {   //노드의 자식 노드가 1개인 경우
        if (deletenode->llink != NULL) {
            childnode = deletenode->llink;      //자식노드 llink인 경우
        }
        else {
            childnode = deletenode->rlink;      //아니면 rlink로 지정
        }
        if (parentnode != NULL) {
            if (parentnode->llink == deletenode) {
                parentnode->llink = childnode;
            }
            else {
                parentnode->rlink = childnode;      //부모노드가 없는 경우도 좌, 우를 자식노드로 지정
            }
        }
        else {
            tree->root = childnode;
        }
        free(deletenode);   //동적 메모리 할당 해제
        return ret;
    }
}

node* search(Tree* tree, int value) {
    node* returnnode = NULL;
    if (tree == NULL) {   //트리가 없을 경우
        return NULL;
    }
    returnnode = tree->root;
    while (returnnode != NULL) {
        if (value == returnnode->value) {
            break;
        }
        else if (value < returnnode->value) {
            returnnode = returnnode->llink;
        }
        else {
            returnnode = returnnode->rlink;
        }
    }
    return returnnode;
}

void printTree(node* treenode, int level) {   //트리 출력 함수
    int i = 0;
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    if (treenode != NULL) {
        printf("-[%d]%d\n", level, treenode->value);
        printTree(treenode->llink, level + 1);
        printTree(treenode->rlink, level + 1);
    }
    else {
        printf("NULL\n");
    }
}

int main(void) {
    Tree* tree = NULL;
    node* searchnode = NULL;
    int value = 0;

    node num1 = { 1 };
    node num2 = { 2 };
    node num3 = { 3 };
    node num4 = { 4 };
    node num5 = { 5 };
    node num6 = { 6 };
    node num7 = { 7 };
    node num8 = { 8 };
    node num9 = { 9 };
    node num10 = { 10 };

    tree = newTree();
    insertnode(tree, num1);
    insertnode(tree, num3);
    insertnode(tree, num5);
    insertnode(tree, num7);
    insertnode(tree, num9);
    insertnode(tree, num8);
    insertnode(tree, num2);
    insertnode(tree, num4);
    insertnode(tree, num6);
    insertnode(tree, num10);
    printTree(tree->root, 10);
    

}
