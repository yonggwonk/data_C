#include <stdio.h>
#define SIZE 10

int sorted[SIZE];	//정렬된 배열 공간

void merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {  // 분할 정렬된 배열 합병
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];;
	} 

	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = arr[l];
		}
	}
	else {	// 남아 있는 값들 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}
	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void merge_sort(int arr[], int left, int right) {	//합병 정렬 과정
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //중간 위치를 계산하여 배열 반으로 나누기
		merge_sort(arr, left, mid); //왼쪽 배열 정렬
		merge_sort(arr, mid + 1, right); // 오른쪽 배열 정렬
		merge(arr, left, mid, right); // 정렬된 배열 결합
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
}	
int main() {
	int arr[SIZE] = { 3,10,2,6,1,7,4,9,5,8 };
	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");
	merge_sort(arr, 0, SIZE - 1);
	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}

}