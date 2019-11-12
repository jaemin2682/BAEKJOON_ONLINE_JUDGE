#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}


int main() {
	int n;
	vector<int> list;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	int ans = list[0];
	for (int i = 1; i < n; i++) ans = gcd(ans, list[i]);
	for (int i = 1; i <= ans; i++) {
		bool check = true;
		for (int j = 0; j < list.size(); j++) {
			if (list[j]%i != 0) {
				check = false;
				break;
			}
		}
		if (check) cout << i << endl;
	}
	return 0;
}