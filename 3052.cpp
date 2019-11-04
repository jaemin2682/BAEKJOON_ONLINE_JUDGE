#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	set<int> set;
	int a;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		a %= 42;
		set.insert(a);
	}

	cout << set.size();

	return 0;
}