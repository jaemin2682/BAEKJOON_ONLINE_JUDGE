#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	vector<int> list(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> list[i];
		list[i] = list[i] * i;
	}
	cout << list[1] << " ";
	for (int i = 1; i < n; i++) {
		cout << list[i + 1] - list[i] << " ";
	}
	
	return 0;
}