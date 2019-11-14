#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);
	int cnt = 1;
	while (!q.empty()) {
		if (cnt % 2 == 1) {
			int tem = q.front();
			q.pop();
			cout << tem << " ";
		}
		else {
			int tem = q.front();
			q.pop();
			q.push(tem);
		}
		cnt++;
	}

	
	return 0;
}