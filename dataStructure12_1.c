#include <stdio.h>
#include <stdlib.h>     
#include <string.h>     

#define MAX 6                  // 정점의 최대 갯수
#define TRUE 1
#define FALSE 0

typedef struct node* P_node;    // 노드포인터
typedef struct node
{
	P_node link;                // 인접리스트 링크
	int vertex;                    //정점
}node;

P_node graph[MAX];              // 인접리스트 배열 크기 지정
int mark[MAX];            // 검색할 리스트 선언
int matrix[MAX][MAX] = {        // 인접행렬 정사각행렬로 임의 생성
				 {0,1,1,0,0,1},
				 {1,0,0,1,1,0},
				 {1,0,0,0,0,1},
				 {0,1,1,0,10},
				 {0,1,0,0,0,1},
				 {0,0,1,1,0,0}
};

void init() // // 인접행렬을 기반으로 인접 리스트 구성하는 함수
{
	int x, y;

	P_node move = NULL;         // 이동포인터
	P_node comp;					  // 비교 포인터
	P_node temp = NULL;          // 동적할당

	for (x = 0; x < MAX; x++)
	{
		comp = graph[x];         // 탐색할 변수 선언
		printf("정점 %d의 인접 리스트", x + 1);
		for (y = 0; y < MAX; y++)
		{
			if (matrix[x][y] != FALSE)  // matrix[x][y] == TRUE
			{

				temp = (P_node)malloc(sizeof(node));
				temp->vertex = y;     // vertex값에 점 번호 

				if (graph[x] == comp)   // 초기상태: 빈 배열일 때
				{     // move가 temp주소값 갖게하고 graph역시 temp의 주소값을 가지도록 설정
					move = temp;
					graph[x] = temp;
					printf("-> %d", (temp->vertex) + 1);
				}
				else       // 연결되어있다면
				{     // 노드를 연결시킴
					move->link = temp;
					move = temp;
					printf("-> %d", (temp->vertex) + 1);

				}

			}
		}
		temp->link = NULL;      //리스트의 끝에 null
		puts("\n");
	}
}

int main()
{
	int v;
	init();
	return 0;
}

