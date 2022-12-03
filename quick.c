#include <stdio.h>
#define SIZE 10

void quick_sort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2]; //중앙값을 피벗으로 설정
	int temp;
	do
	{
		while (arr[left] < pivot) //left가 pivot보다 큰 값이나 pivot을 만날 때 까지
			left++;
		while (arr[right] > pivot) //right가 pivot보다 작은 값이나 pivot을 만날 때 까지
			right--;
		if (left <= right)    //left가 right보다 왼쪽에 있을 시
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp; 
			left++;
			right--;	//피벗을 중심으로 분리 완료
		}
	} while (left <= right);
	if (L < right) {	//왼쪽의 요소들 다시 퀵정렬
		quick_sort(arr, L, right);
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
	if (left < R) {		//오늘쪽 요소들 다시 퀵정렬
		quick_sort(arr, left, R);
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}	
		printf("\n");
	}
}

int main() {
	int i;
	int arr[SIZE] = { 3,10,2,6,1,7,4,9,5,8 };
	for (i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");
	quick_sort(arr, 0, SIZE - 1);

}