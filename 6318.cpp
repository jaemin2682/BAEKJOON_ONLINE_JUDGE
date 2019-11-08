#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int cnt = 1;
	while (1) {
		int n, num, res=0, sum=0;
		vector<int> list;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> num;
			sum += num;
			list.push_back(num);
		}
		sum /= n;
		for (int i = 0; i < n; i++) {
			if (list[i] - sum > 0) res += list[i] - sum;
		}

		
		cout << "Set #" << cnt << endl;
		cnt++;
		cout << "The minimum number of moves is " << res << "." << endl << endl;
	}

	return 0;
}

