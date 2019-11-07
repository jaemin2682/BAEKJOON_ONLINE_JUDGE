#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int bindo[8001];

int main() {
	int n, sum=0, maxval=-4001, minval=4001;
	vector<int> list;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
		maxval = max(maxval, a);
		minval = min(minval, a);
		if (a < 0) bindo[4000 + abs(a)]++;
		else bindo[a]++;
		list.push_back(a);
	}
	sort(list.begin(), list.end());
	vector<int> bin;
	int maxbin = -4001;
	for (int i = 0; i <= 8000; i++) {
		maxbin = max(maxbin, bindo[i]);
	}
	for (int i = 0; i <= 8000; i++) {
		if (bindo[i] == maxbin) {
			if (i >= 4001) {
				int tem = (i - 4000) * -1;
				bin.push_back(tem);
			}
			else bin.push_back(i);
		}
	}
	sort(bin.begin(), bin.end());

	cout << round((double)sum/n) << endl;
	cout << list[n / 2] << endl;
	if (bin.size() >= 2) cout << bin[1] << endl;
	else cout << bin[0] << endl;
	cout << abs(maxval - minval);

	return 0;
}

