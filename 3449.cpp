#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string a, b;
		int cnt = 0;
		cin >> a >> b;

		for (int j = 0; j < a.size(); j++)
			if (a[j] != b[j]) cnt++;
		cout << "Hamming distance is " << cnt << "." << endl;
	}
	return 0;
}