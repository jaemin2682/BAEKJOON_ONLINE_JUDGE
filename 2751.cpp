#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n, arr[1000000], sorted[1000000];

void merge(int left, int mid, int right) {	// left ~ mid와 mid+1 ~ right의 합병
	int i = left, j = mid + 1, k = left;//정렬된 왼쪽 리스트의 인덱스, 정렬된 오른쪽 리스트의 인덱스, 정렬된 리스트의 인덱스

	while (i <= mid && j <= right) {	//분할 정렬된 list의 합병
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}

	if (i > mid)  // 남아있는 값들을 일괄 복사
		for (int l = j; l <= right; l++) 
			sorted[k++] = arr[l];

	else 	// 남아있는 값들을 일괄 복사
		for (int l = i; l <= mid; l++) 
			sorted[k++] = arr[l];

	for (int l = left; l <= right; l++) arr[l] = sorted[l];	//정렬된 sorted를 list로 재복사
}

void partition(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;	//중간위치 계산해서 리스트 균등 분할 - 분할(Divide)
		partition(left, mid);	//앞쪽 부분 리스트 정렬 - 정복(Conquer)
		partition(mid + 1, right);	//뒤쪽 부분 리스트 정렬 - 정복(Conquer)
		merge(left, mid, right);	//정렬된 2개의 부분 배열을 합병 - 결합(Combine)
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

