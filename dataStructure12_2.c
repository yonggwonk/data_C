#include <stdio.h>
#define SIZE 6

typedef struct {
	int uppoint;
	int distance;
}p;

void dijkstra_find(p* point, int graph[][SIZE], int* distance);
int min_find(int* footstep, int* distance);


void dijkstra_find(p* point, int graph[][SIZE], int* distance)   // 다익스트라 알고리즘
{
	int footstep[SIZE] = { 1, 0 };  // 탐색을 완료한 정점(VO는 방문처리)
	for (int i = 0; i < SIZE; i++)  //0으로부터 연결된 정점 추가
	{
		distance[i] = graph[0][i];
		point[i].uppoint = 0;
		point[i].distance = distance[i];
	}
	
	int i;
	while ((i = min_find(footstep, distance)) != -1)		//정점을 모두 탐색할때까지 반복
	{
		footstep[i] = 1;  // 탐색완료 처리
		for (int j = 1; j < SIZE; j++)
		{ 
			if (graph[i][j] != 0 && (distance[i] + graph[i][j] < distance[j] || distance[j] == 0))		//새로운 vertex의 길이가 기존의 길이보다 짧거나, 0이라면 새로 지정
			{
				distance[j] = distance[i] + graph[i][j];
				point[j].uppoint = i;
				point[j].distance = distance[j];
			}
		}
	}
}


int min_find(int* footstep, int* distance)		// 탐색하지 않은 정점의 최단거리 찾기
{
	int min = 10000;
	int j = -1;
	for (int i = 1; i < SIZE; i++)
		if (distance[i] != 0 && distance[i] < min && footstep[i] == 0)
		{
			min = distance[i];
			j = i;
		}
	if (j == -1)  // 모두 탐색했을 경우
		return -1;
	else  // 탐색할 정점이 남은 경우
		return j;
}

void main()
{
	int graph[][SIZE] = {		//포인트 간의 거리를 입력하여 그래프 정보를 인접배열로 나타냄
		{0,0,25,15,0,0},
		{15,0,0,0,10,0},
		{10,50,0,0,65,0},
		{0,20,0,0,35,0},
		{0,0,0,30,0,0},
		{0,0,0,3,0,0}
	};
	p point[SIZE];		//탐색변수

	// VO -> 다른 정점으로의 거리 변수
	int distance[SIZE] = { 0 };

	// 최단거리 찾기 
	dijkstra_find(point, graph, distance);

	printf("\n");

	for (int i = 0; i < SIZE; i++)		//출력 
		printf("   v0에서 v%d까지의 최단거리: %d\n",
			i, point[i].distance);
	printf("\n   ");
}