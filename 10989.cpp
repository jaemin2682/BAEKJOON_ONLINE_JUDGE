#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
const int MAX = 10001;

int n, arr[MAX];

void CountingSort() {
	for (int i = 1; i < MAX; i++) {
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i < MAX; i++) {
		int idx = arr[i] - arr[i - 1];
		while (idx!=0) {
			printf("%d\n", i);
			idx--;
		}
	}
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[a]++;
	}

	CountingSort();

	return 0;
}

