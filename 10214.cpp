#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int y, k, yscore = 0, kscore = 0;
		for (int j = 0; j < 9; j++) {
			cin >> y >> k;
			if (y > k) yscore++;
			else if (y < k) kscore++;
		}
		if (yscore > kscore) cout << "Yonsei" << endl;
		else if (yscore < kscore) cout << "Korea" << endl;
		else cout << "Draw" << endl;
	}

	return 0;
}