#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		scanf("%d", &num);
		int cnt = 0;

		for (int j = 5; j <= num; j *= 5) {
			cnt += num / j;
		}
		printf("%d \n", cnt);
	}
	return 0;
}