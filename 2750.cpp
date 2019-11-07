#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int map[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i -1; j++) {
			if (map[j] > map[j + 1]) {
				int temp = map[j + 1];
				map[j + 1] = map[j];
				map[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << map[i] << endl;
	}

	return 0;
}

