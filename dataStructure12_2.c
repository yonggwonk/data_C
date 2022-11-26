#include <stdio.h>
#define SIZE 6

typedef struct {
	int uppoint;
	int distance;
}p;

void dijkstra_find(p* point, int graph[][SIZE], int* distance);
int min_find(int* footstep, int* distance);


void dijkstra_find(p* point, int graph[][SIZE], int* distance)   // ���ͽ�Ʈ�� �˰���
{
	int footstep[SIZE] = { 1, 0 };  // Ž���� �Ϸ��� ����(VO�� �湮ó��)
	for (int i = 0; i < SIZE; i++)  //0���κ��� ����� ���� �߰�
	{
		distance[i] = graph[0][i];
		point[i].uppoint = 0;
		point[i].distance = distance[i];
	}
	
	int i;
	while ((i = min_find(footstep, distance)) != -1)		//������ ��� Ž���Ҷ����� �ݺ�
	{
		footstep[i] = 1;  // Ž���Ϸ� ó��
		for (int j = 1; j < SIZE; j++)
		{ 
			if (graph[i][j] != 0 && (distance[i] + graph[i][j] < distance[j] || distance[j] == 0))		//���ο� vertex�� ���̰� ������ ���̺��� ª�ų�, 0�̶�� ���� ����
			{
				distance[j] = distance[i] + graph[i][j];
				point[j].uppoint = i;
				point[j].distance = distance[j];
			}
		}
	}
}


int min_find(int* footstep, int* distance)		// Ž������ ���� ������ �ִܰŸ� ã��
{
	int min = 10000;
	int j = -1;
	for (int i = 1; i < SIZE; i++)
		if (distance[i] != 0 && distance[i] < min && footstep[i] == 0)
		{
			min = distance[i];
			j = i;
		}
	if (j == -1)  // ��� Ž������ ���
		return -1;
	else  // Ž���� ������ ���� ���
		return j;
}

void main()
{
	int graph[][SIZE] = {		//����Ʈ ���� �Ÿ��� �Է��Ͽ� �׷��� ������ �����迭�� ��Ÿ��
		{0,0,25,15,0,0},
		{15,0,0,0,10,0},
		{10,50,0,0,65,0},
		{0,20,0,0,35,0},
		{0,0,0,30,0,0},
		{0,0,0,3,0,0}
	};
	p point[SIZE];		//Ž������

	// VO -> �ٸ� ���������� �Ÿ� ����
	int distance[SIZE] = { 0 };

	// �ִܰŸ� ã�� 
	dijkstra_find(point, graph, distance);

	printf("\n");

	for (int i = 0; i < SIZE; i++)		//��� 
		printf("   v0���� v%d������ �ִܰŸ�: %d\n",
			i, point[i].distance);
	printf("\n   ");
}