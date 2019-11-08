#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int list[41];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);

		list[1] = 1;
		list[2] = 1;
		for (int i = 3; i <= 40; i++) {
			list[i] = list[i - 1] + list[i - 2];
		}


		if (n == 0) cout << "1 0" << endl;
		else if (n == 1) cout << "0 1" << endl;
		else {
			cout << list[n-1] << " "  <<list[n] << endl;
		}
	}

	return 0;
}