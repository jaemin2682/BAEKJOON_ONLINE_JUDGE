#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool check[20000];

int d(int num) {
	int sum = 0;
	string a = to_string(num);

	for (int i = 0; i < a.size(); i++) {
		sum += a[i] - 48;
	}

	return num + sum;
}


int main() {
	
	for (int i = 1; i < 10000; i++) {
		check[d(i)] = true;
	}

	for (int i = 1; i < 10000; i++) {
		if (!check[i]) cout << i << endl;
	}

	return 0;
}