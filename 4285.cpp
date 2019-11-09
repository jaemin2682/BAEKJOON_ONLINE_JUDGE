#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	while (1) {
		int k, m, num;
		bool pass = true;
		vector<int> chosen;
		
		cin >> k;
		if (k == 0) return 0;
		cin >> m;
		for (int i = 0; i < k; i++) {
			cin >> num;
			chosen.push_back(num);
		}
		for (int i = 0; i < m; i++) {
			int c, r, cnt=0;
			cin >> c >> r;
			vector<int> tem;
			for (int j = 0; j < c; j++) {
				cin >> num;
				for (int a = 0; a < k; a++) {
					if (chosen[a] == num) {
						cnt++;
						break;
					}
				}
			}
			if (cnt < r) pass = false;
		}
		if (pass) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}

