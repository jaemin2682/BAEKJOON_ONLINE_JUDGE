#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> listA(n);
	vector<int> listB(n);

	for (int i = 0; i < n; i++) cin >> listA[i];
	for (int i = 0; i < n; i++) {
		cin >> listB[i];
	}
	sort(listA.begin(), listA.end());
	sort(listB.begin(), listB.end(), greater<int>());
	
	int val = 0;
	for (int i = 0; i < n; i++) {
		val += listA[i] * listB[i];
	}

	cout << val;
	return 0;
}


