//삽입 삭제 탐색
//임의의 배열 생성 후 배열의 원소를 heap을 통해 정렬

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct heapNode {
	int value;
}heapNode;	//힙의 각 노드에 들어갈 값을 구조체로 정의

typedef struct heap {
	int maxnum;		//힙에 최대 몇 개의 수를 넣은건지 저장하는 변수
	int currentnum;		//현재 몇 개의 수가 저장되어 있는 지 저장하는 변수
	heapNode* element;
}heap;		//힙 정의

heap* newHeap(int maxnumber){	//새로운 힙 생성
	heap* pHeap;

	pHeap = (heap*)malloc(sizeof(heap));
	if (pHeap == NULL)
		return (NULL);
	pHeap->maxnum = maxnumber;	//입력받은 최대 수 저장
	pHeap->currentnum = 0;
	pHeap->element = (heapNode*)malloc(sizeof(heapNode) * (maxnumber + 1)); //maxnumber+1개 만큼의 공간 동적 할당
	if (pHeap->element == NULL)
	{
		free(pHeap);
		return (NULL);
	}
	return (pHeap);		//새로 생성한 힙을 반환
}

int	insertMaxHeap(heap* pHeap, heapNode element){	//힙의 구성 원소 추가
	int	i;	
	int	parent;		

	if (pHeap == NULL || pHeap->currentnum == pHeap->maxnum)	//힙이 가득 차있는 힙이라면 거짓을 반환(삽입불가)
		return (FALSE);
	pHeap->currentnum++;		//힙의 현재 원소 수를 1 더함
	i = pHeap->currentnum;		
	parent = i / 2;		//부모노드의 값을 지정
	while (i > 1 && element.value >= pHeap->element[parent].value)
	{
		pHeap->element[i].value = pHeap->element[parent].value;
		i /= 2;
		parent = i / 2;		//부모 노드보다 작게 될 때 까지 i를 반감하며 연산
	}
	pHeap->element[i] = element;		//반복문을 탈출했을 때 힙의 i번째 원소에 element를 저장
	return (TRUE);
}

int	deleteMaxHeapNode(heap* pHeap)		//노드 삭제 함수
{
	int	arrayindex;
	int	llink;
	int	rlink;
	int	big;
	int	tmp;

	if (pHeap == NULL || pHeap->currentnum == 0)		//힙이 비어있는 힙이라면 거짓 반환(원소 삭제 불가)
		return (FALSE);
	arrayindex = 1;		//힙을 탐색할 배열의 인덱스 설정
	pHeap->element[arrayindex].value = pHeap->element[pHeap->currentnum].value;
	pHeap->currentnum--;
	while (arrayindex < pHeap->currentnum)	//배열의 index가 현재 노드의 개수보다 커질때까지
	{
		llink = arrayindex * 2;		
		rlink = arrayindex * 2 + 1;
		big = llink;
		if (rlink <= pHeap->currentnum && pHeap->element[llink].value < pHeap->element[rlink].value)	//왼쪽의 노드값이 오른쪽보다 크다면, 큰 값은 오른쪽이라고 재저장
			big = rlink;
		if (pHeap->element[arrayindex].value < pHeap->element[big].value)		//arrayindex번쨰의 값이 big번째의 값보다 작다면
		{
			tmp = pHeap->element[arrayindex].value;
			pHeap->element[arrayindex].value = pHeap->element[big].value;
			pHeap->element[big].value = tmp;
		}	//두 값의 순서를 재정의(내림차순으로 바꿈)
		arrayindex = big;
	}
	return (TRUE);
}


void displayHeap(heap* pHeap)		//힙을 통한 완전 이진 트리 출력
{
	int	i,j;
	int	two;
	int	height;
	int	count;

	if (pHeap == NULL)		//입력한 힙이 비어있는 메모리라면 오류 메세지 출력
	{
		printf("힙이 비어있습니다.");		
		return;
	}
	if (pHeap->currentnum == 0)		//힙의 현재 개수가 0이 된다면 비어있다는 메세지 출력
	{
		printf("힙이 비었습니다.\n");
		return;
	}
	height = 0;		//tree의 level 초기설정
	count = pHeap->currentnum;	//현재 갯수를 저장
	while (count != 0)		//현재 갯수가 0이 될때까지
	{
		count /= 2;		//갯수를 2로 나눔
		height++;		//나눌 떄 마다 level을 1씩 더함
	}
	two = 1;
	for (i = 0; i < height; i++)
	{
		for (j = two; j < two * 2; j++)
		{
			if (j > pHeap->currentnum)
				break;
			printf("%d\t", pHeap->element[j].value);
		}
		printf("\n");
		two *= 2;
	}
	printf("\n");
}

int main(void) {
	heap* pHeap;
	heapNode element;

	int arr[15] = { 2,4,6,8,10,1,3,5,7,9,15,14,13,12,11 };		//15개짜리 임의의 배열 생성
	pHeap = newHeap(15);		//힙 초기화
	for (int i = 0; i < 15; i++) {

		element.value = arr[i];
		insertMaxHeap(pHeap, element);			//힙 추가, 5개, 10개 추가할때마다 트리가 보이도록 설정
		if (i == 4) {
			displayHeap(pHeap);
			continue;
		}
		if (i == 9) {
			displayHeap(pHeap);
			continue;
		}
	}
	displayHeap(pHeap);

	

	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	displayHeap(pHeap);

	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	displayHeap(pHeap);

}