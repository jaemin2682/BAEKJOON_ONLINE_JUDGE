#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	char n[8];
	int arr[10] = { 0, };
	int max=0;
	scanf("%s", n);

	for (int i = 0; i < strlen(n);i++) {
		arr[(int)n[i]-48]++;
	}
	arr[6] = arr[6] + arr[9];
	arr[6] = ceil((float)arr[6] / 2);
	arr[9] = 0;

	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) max = arr[i];
	}

	printf("%d", max);

	return 0;
}