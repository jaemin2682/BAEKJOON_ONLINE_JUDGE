#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n, arr[1000000], sorted[1000000];

void merge(int left, int mid, int right) {	// left ~ mid�� mid+1 ~ right�� �պ�
	int i = left, j = mid + 1, k = left;//���ĵ� ���� ����Ʈ�� �ε���, ���ĵ� ������ ����Ʈ�� �ε���, ���ĵ� ����Ʈ�� �ε���

	while (i <= mid && j <= right) {	//���� ���ĵ� list�� �պ�
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}

	if (i > mid)  // �����ִ� ������ �ϰ� ����
		for (int l = j; l <= right; l++) 
			sorted[k++] = arr[l];

	else 	// �����ִ� ������ �ϰ� ����
		for (int l = i; l <= mid; l++) 
			sorted[k++] = arr[l];

	for (int l = left; l <= right; l++) arr[l] = sorted[l];	//���ĵ� sorted�� list�� �纹��
}

void partition(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;	//�߰���ġ ����ؼ� ����Ʈ �յ� ���� - ����(Divide)
		partition(left, mid);	//���� �κ� ����Ʈ ���� - ����(Conquer)
		partition(mid + 1, right);	//���� �κ� ����Ʈ ���� - ����(Conquer)
		merge(left, mid, right);	//���ĵ� 2���� �κ� �迭�� �պ� - ����(Combine)
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	partition(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

