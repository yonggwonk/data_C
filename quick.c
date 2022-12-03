#include <stdio.h>
#define SIZE 10

void quick_sort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2]; //�߾Ӱ��� �ǹ����� ����
	int temp;
	do
	{
		while (arr[left] < pivot) //left�� pivot���� ū ���̳� pivot�� ���� �� ����
			left++;
		while (arr[right] > pivot) //right�� pivot���� ���� ���̳� pivot�� ���� �� ����
			right--;
		if (left <= right)    //left�� right���� ���ʿ� ���� ��
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp; 
			left++;
			right--;	//�ǹ��� �߽����� �и� �Ϸ�
		}
	} while (left <= right);
	if (L < right) {	//������ ��ҵ� �ٽ� ������
		quick_sort(arr, L, right);
		for (int i = 0; i < SIZE; i++) {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
	}
	if (left < R) {		//������ ��ҵ� �ٽ� ������
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