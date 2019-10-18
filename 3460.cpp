#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
vector<int> arr;
vector<int> store;
vector<int> print;
// 13  6  3   1
//   1   0  1
void bin(int num) {
	while (num != 1) {
		store.push_back(num % 2);
		num /= 2;
	}
	store.push_back(1);
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr.push_back(n);
	}

	for (int i = 0; i < t; i++) {
		bin(arr[i]);
		for (int j = 0; j < store.size(); j++) {
			if (store[j] == 1) print.push_back(j);
		}
		sort(print.begin(), print.end());
		for (int j = 0; j < print.size(); j++) {
			cout << print[j] << " ";
		}
		cout << endl;
		store.erase(store.begin(), store.end());
		print.erase(print.begin(), print.end());
	}


	return 0;
}