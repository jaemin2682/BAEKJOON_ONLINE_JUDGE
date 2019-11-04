#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int c, n, a;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		vector<int> list;
		double sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> a;
			list.push_back(a);
			sum += a;
		}
		sum /= n;
		double cnt = 0;
		for (int j = 0; j < n; j++) {
			if (list[j] > sum) cnt++;
		}
		printf("%.3f", cnt / n * 100);
		cout << "%" << endl;
	}

	return 0;
}