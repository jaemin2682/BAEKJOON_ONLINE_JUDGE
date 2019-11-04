#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> list;
	for (int i = 0; i < 8; i++) {
		int a;
		cin >> a;
		list.push_back(a);
	}
	vector<int> temp = list;
	sort(list.begin(), list.end());
	if (temp == list) {
		cout << "ascending";
		return 0;
	}
	sort(list.begin(), list.end(), greater<int>());
	if (temp == list) {
		cout << "descending";
		return 0;
	}
	cout << "mixed";

	return 0;
}