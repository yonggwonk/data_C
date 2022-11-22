#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int value;
    struct node* llink;
    struct node* rlink;      //linked ����Ʈ ����ü ����
}node;

typedef struct Tree {
    node* root;
}Tree;      //Ʈ�� ����ü ����

Tree* newTree() {
    Tree* nullspace = NULL;
    nullspace = (Tree*)malloc(sizeof(Tree));
    if (nullspace != NULL)
        nullspace->root = NULL;
    return nullspace;
}      //���ο� ���� Ž�� Ʈ�� ����, tree�� ������ �޸𸮸� �����Ҵ�����

int insertnode(Tree* tree, node element) {   //���ο� ���� Ʈ���� ����
    node* parentnode = NULL;
    int ret = TRUE;

    if (tree == NULL) {
        int ret = FALSE;
        return ret;
    }      //tree�� ������� �� ������ ��ȯ
    parentnode = tree->root;
    while (parentnode != NULL) {
        if (element.value == parentnode->value) {
            printf("�ߺ��� �� �Դϴ�.\n");   //������ �����ϴ� ���� ���� ��� ���� ��ȯ
            ret = FALSE;
            return ret;
        }
        else if (element.value < parentnode->value) { //�Է¹��� ���� ���� ��庸�� ���� ��
            if (parentnode->llink == NULL) {      //������ ������ �����Ѵٸ�
                break;
            }
            else {
                parentnode = parentnode->llink;   //���ٸ� ���� ����Ʈ���� ���� �Ҵ� �� ����
            }
        }
        else {
            parentnode = parentnode->rlink;  //�Է¹��� ���� ���� ��庸�� Ŭ �� ������ ����Ʈ���� �̵�
        }
    }
    node* newnode = NULL;
    newnode = (node*)malloc(sizeof(node));
    if (newnode != NULL) {
        *newnode = element;
        newnode->llink = NULL;
        newnode->rlink = NULL;

        if (parentnode == NULL) {
            tree->root = newnode;   //�θ� ��尡 ���� �� ���ο� ��Ʈ�� ����
        }
        else {
            if (newnode->value < parentnode->value) {   //�θ� ���� ���Ͽ� �� ������
                parentnode->llink = newnode;   //���� ������ ����
            }
            else {
                parentnode->rlink = newnode;   //������ ������ ����
            }
        }
        ret = TRUE;
    }
    return ret;
}

int deletenode(Tree* tree, int value) {      //������ ���� �Է¹޾� ����
    int ret = TRUE;
    node* deletenode;
    node* parentnode;
    node* lchild;
    node* rchild;
    node* childnode;

    if (tree == NULL) {      //������ ��带 Ž���ϴ� �ڵ�
        ret = FALSE;
        return ret;
    }
    parentnode = NULL;
    deletenode = tree->root;
    while (deletenode != NULL) {
        if (value == deletenode->value) {      //�����Ϸ��� ���� �Է¹��� ���� ���ٸ� �ٷ� �����Ϸ� �̵�
            break;
        }
        parentnode = deletenode;
        if (value < deletenode->value) {
            deletenode = deletenode->llink;
        }
        else {
            deletenode = deletenode->rlink;      //���� ũ�⸦ ���ϸ� �ڽ� ��带 �̵��ϸ� Ž��
        }
    }
    if (deletenode == NULL) {
        printf("�ش� ���� Ʈ���� �������� �ʽ��ϴ�.\n");
        ret = FALSE;
        return ret;
    }

    //���� �� �θ� ���� link �ٽ� �Ҵ�
    if (deletenode->llink == NULL && deletenode->rlink == NULL) {      //������ ����� �ڽ� ��尡 ���� ��
        if (parentnode != NULL) {
            if (parentnode->llink == deletenode) {
                parentnode->llink = NULL;
            }
            else {
                parentnode->rlink = NULL;  //�θ����� r,lŽ�� �� NULL���� ����
            }
        }
        else {
            tree->root = NULL;   //�θ��尡 ����ٸ� root�� null����
        }
    }
    else if (deletenode->llink != NULL && deletenode->rlink != NULL) {   //������ ����� �ڽ� ��尡 2��
        lchild = deletenode;
        rchild = deletenode->llink;

        while (rchild->rlink != NULL) {      //���� �ڽ� Ʈ���� �ִ�
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
                parentnode->rlink = rchild;      //�θ��尡 ������ ������ ��尡 llink���, llink�� rchild ����
            }
        }
        else {
            tree->root = rchild;      //���� �� ��Ʈ�� �ٷ� ����
        }
    }
    else {   //����� �ڽ� ��尡 1���� ���
        if (deletenode->llink != NULL) {
            childnode = deletenode->llink;      //�ڽĳ�� llink�� ���
        }
        else {
            childnode = deletenode->rlink;      //�ƴϸ� rlink�� ����
        }
        if (parentnode != NULL) {
            if (parentnode->llink == deletenode) {
                parentnode->llink = childnode;
            }
            else {
                parentnode->rlink = childnode;      //�θ��尡 ���� ��쵵 ��, �츦 �ڽĳ��� ����
            }
        }
        else {
            tree->root = childnode;
        }
        free(deletenode);   //���� �޸� �Ҵ� ����
        return ret;
    }
}

node* search(Tree* tree, int value) {
    node* returnnode = NULL;
    if (tree == NULL) {   //Ʈ���� ���� ���
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

void printTree(node* treenode, int level) {   //Ʈ�� ��� �Լ�
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