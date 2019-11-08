#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int i = 1;
	while (1) {
		int Z, I, M, L;
		cin >> Z >> I >> M >> L;
		if (Z == 0 && I == 0 && M == 0 && L == 0) break;

		L = (Z*L + I) % M;
		int cnt = 1;
		int next = (Z*L + I) % M;
		while (1) {
			if (next == L) break;
			next = (Z*next + I) % M;
			cnt++;
		}

		cout << "Case " << i << ": " << cnt << endl;
		i++;

	}

	return 0;
}

