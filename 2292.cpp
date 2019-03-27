#include <iostream>
using namespace std;

int main() {
	int n, res, num = 1;
	scanf("%d", &n);

	if (n == 1) res = 0;
	else {
		for (int i = 1; i < n; i++) {
			num = num + 6 * i;
			if (num >= n) {
				res = i;
				break;
			}
		}
	}
	printf("%d", res + 1);

	return 0;
}