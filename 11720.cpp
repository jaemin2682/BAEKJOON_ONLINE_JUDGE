#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, sum=0;
	string str;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		sum += str[i] - 48;
	}
	cout << sum;
	return 0;
}