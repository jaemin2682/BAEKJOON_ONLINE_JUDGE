#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int p, m;
		cin >> p >> m;
		vector<bool> seat(m+1);
		for (int j = 1; j < m + 1; j++) seat[i] = false;
		for (int j = 1; j <= p; j++) {
			int person;
			cin >> person;
			seat[person] = true;
		}
		int cnt = 0;
		for (int j = 1; j <= m; j++)
			if (seat[j]) cnt++;
		cout << p - cnt << endl;
	}
	return 0;
}