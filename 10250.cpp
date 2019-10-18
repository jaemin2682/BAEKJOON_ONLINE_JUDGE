#include <iostream>
using namespace std;

int main() {
	int t, h, w, n;
	int realh, realw;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);
		realw = 1;
		for (int j = 1;; j++) {
			if (n > h) {
				n = n - h;
				realw++;
			}
			else { 
				realh = n;
				break;
			}
		}
		printf("%d\n", realh * 100 + realw);
	}
}