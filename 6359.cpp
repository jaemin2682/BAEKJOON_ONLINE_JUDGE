#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int t;
	bool lock[101];
	cin >> t;
	for (int i = 0; i < t; i++) {
		int round = 2;
		memset(lock, false, sizeof(lock));
		int num;
		cin >> num;
		while (round <= num) {
			for (int i = round; i <= num; i += round) {
				if (lock[i] == true) lock[i] = false;
				else lock[i] = true;
			}
			round++;
		}
		int cnt = 0;
		for (int i = 1; i <= num; i++) {
			if (lock[i] == false) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}