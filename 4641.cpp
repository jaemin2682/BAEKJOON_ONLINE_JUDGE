#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int a;
	while (1) {
		vector<int> arr;
		int cnt = 0;
		while (1) {
			cin >> a;
			if (a == -1) return 0;
			if (a == 0) break;
			arr.push_back(a);
		}
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr.size(); j++) {
				if (arr[i] * 2 == arr[j]) {
					cnt++;
					break;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}