#include <stdio.h>
#define SIZE 10

void bubble_sort(int* arr) {
	int i, j, k, temp;		
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE - i - 1; j++) {	//최악의 경우 n-1번 시행
			if (arr[j] > arr[j + 1]) {  
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;		//j번째와 j+1번째 비교 후 왼쪽이 더 크면 교환
			}
		}
		for (k = 0; k < SIZE; k++) {
			printf("[%d] ", arr[k]);	//한 사이클 돌 때 마다 출력
		}
		printf("\n");
	}
}

int main() {
	int arr[SIZE] = { 3,10,2,6,1,7,4,9,5,8 };		//크기 10의 배열 지정
	printf("초기 배열:");
	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");
	bubble_sort(arr);	//bubble sort출력
}