#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n, m, maxhel = 0, maxjog = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		maxhel = max(maxhel, num);
	}
	for(int i=0;i<m;i++) {
		int num;
		cin >> num;
		maxjog = max(maxjog, num);
	}
	cout << maxhel + maxjog;
	return 0;
}