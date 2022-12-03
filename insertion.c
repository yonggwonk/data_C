#define SIZE 10
#include <stdio.h>

void insertion_sort(int* list) {
	int i, j, k, key;

	for (i = 1; i < SIZE; i++) {
		key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		for (j = i - 1; j >= 0 && list[j] > key; j--) { 
			list[j + 1] = list[j]; //key값보다 리스트 값이 작은 경우 한 칸 뒤로 이동
		}
		list[j + 1] = key; //조건을 만족하면 key 저장 후 멈춤

		for (k = 0; k < SIZE; k++) {
			printf("[%d] ", list[k]);
		}
		printf("\n");
	}
}

int main() {
	int arr[SIZE] = { 3,10,2,6,1,7,4,9,5,8 };		//크기 10의 배열 지정

	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");
	insertion_sort(arr);	//insertion sort 출력

}