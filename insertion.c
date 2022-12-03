#define SIZE 10
#include <stdio.h>

void insertion_sort(int* list) {
	int i, j, k, key;

	for (i = 1; i < SIZE; i++) {
		key = list[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

		for (j = i - 1; j >= 0 && list[j] > key; j--) { 
			list[j + 1] = list[j]; //key������ ����Ʈ ���� ���� ��� �� ĭ �ڷ� �̵�
		}
		list[j + 1] = key; //������ �����ϸ� key ���� �� ����

		for (k = 0; k < SIZE; k++) {
			printf("[%d] ", list[k]);
		}
		printf("\n");
	}
}

int main() {
	int arr[SIZE] = { 3,10,2,6,1,7,4,9,5,8 };		//ũ�� 10�� �迭 ����

	for (int i = 0; i < SIZE; i++) {
		printf("[%d] ", arr[i]);
	}
	printf("\n");
	insertion_sort(arr);	//insertion sort ���

}