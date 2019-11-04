#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> list;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		list.push_back(a);
	}
	sort(list.begin(), list.end());
	cout << list[0] << " " << list[list.size() - 1];



	return 0;
}