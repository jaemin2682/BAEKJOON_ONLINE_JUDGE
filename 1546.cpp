#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n, a, m=0;
	double sum=0;
	vector<double> list;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		m = max(a, m);
		list.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		list[i] = list[i] / m * 100;
		sum += list[i];
	}

	cout << sum / n;


	return 0;
}