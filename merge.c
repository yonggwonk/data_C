#include <stdio.h>
#define SIZE 10

int sorted[SIZE];	//���ĵ� �迭 ����

void merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {  // ���� ���ĵ� �迭 �պ�
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
	else {	// ���� �ִ� ���� ����
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}
	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void merge_sort(int arr[], int left, int right) {	//�պ� ���� ����
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //�߰� ��ġ�� ����Ͽ� �迭 ������ ������
		merge_sort(arr, left, mid); //���� �迭 ����
		merge_sort(arr, mid + 1, right); // ������ �迭 ����
		merge(arr, left, mid, right); // ���ĵ� �迭 ����
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