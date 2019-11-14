#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool Reexam = true;
		for (int j = 1; j <= 10; j++) {
			int num;
			cin >> num;
			if (num != ((j - 1) % 5) + 1) {
				Reexam = false;
			}
		}
		if (Reexam) cout << i + 1 << endl;
	}
	return 0;
}