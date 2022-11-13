#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[30];
	double score;
}element;	//학생정보 구조체 정의

typedef struct Node {
	element data;
	struct Node* llink;
	struct Node* rlink;
}Node;		//이중연결리스트 구조체 정의

Node* head;
Node* tail;
void init() //이중 연결 리스트 초기화 함수
{
	head = (Node*)malloc(sizeof(Node)); 
	tail = (Node*)malloc(sizeof(Node)); 
	head->rlink = tail;   
	head->llink = head;      
	tail->llink = head;      
	tail->rlink = tail;      
}


void append(Node* before,Node* newnode) // 삽입 함수(before 노드의 오른쪽에 data 삽입)
{
	if (head->rlink == tail)
	{
		head->rlink = newnode;
		newnode->llink - head;
		newnode->rlink = tail;
		tail->llink = newnode;
		return;
	}
	else {
		tail->llink->rlink = newnode;
		newnode->llink = tail->llink;
		newnode->rlink = tail;
		tail->llink = newnode;
		return;
	}
	
}

void Delete(Node* temp) {
	Node* node;
	node= head->rlink;      // 이동할포인터는 헤드다음부터 시작
	while (strcmp(node->data.name,temp->data.name) != 0 && node != tail)         // 문자열 찾거나 꼬리에 도달하면 정지
	{
		node = node->rlink;
	}
	
	if (node == tail)
	{
		printf("학생이 존재하지 않습니다.\n");
	}
	else
	{
		node->llink->rlink = node->rlink;
		node->rlink->llink = node->llink;         //옮겨간 노드의 상태로 재설정
		free(node);      //메모리 동적할당 해제
		printf("삭제 성공\n");
		return;		
	}
	
}

void search(element data) {
	Node* ptr;
	ptr = head->rlink;
	while (strcmp(ptr->data.name,data.name ) != 0 && ptr != tail)
	{
		ptr = ptr->rlink;
	}
	if (ptr == tail)
	{
		printf("해당학생을 찾을 수 없습니다");
	}
	else
	{
		printf(" %f점 입니다.\n",ptr->data.score);

	}
}



int main(void) {
	element stu;
	Node* temp;
	
	int input = 0;
	init();
	while (1) {
		Node* head = (Node*)malloc(sizeof(Node));
		
		printf("\n자료구조 시험성적 관리\n\n");
		printf("실행할 기능을 입력하세요\n");
		printf("1. 입력\n2. 제거\n3. 검색\n4.종료\n");
		scanf_s("%d", &input);
		if (input == 1) {
			temp = (Node*)malloc(sizeof(Node));
			printf("추가할 학생 이름:");
			scanf_s("%s", stu.name, sizeof(stu.name));
			printf("점수:");
			scanf_s("%lf", &stu.score);
			temp->data = stu;
			append(head,temp);
		}
		else if (input == 2) {
			temp = (Node*)malloc(sizeof(Node));
			printf("삭제할 학생 이름:\n");
			scanf_s("%s", stu.name, sizeof(stu.name));
			temp->data = stu;
			Delete(temp);
		}
		else if (input == 3)
		{
			printf("검색할 학생 이름:\n");
			scanf_s("%s", stu.name, sizeof(stu.name));
			search(stu);
		}
			
		else if (input == 4)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else
			continue;
	}
}