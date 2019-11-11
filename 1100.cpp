#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int main() {
	int cnt = 0;
	char chess;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chess;
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
				if (chess == 'F') cnt++;
		}
	}
	cout << cnt;

	return 0;
}