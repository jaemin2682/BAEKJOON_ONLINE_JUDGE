	#include <iostream>
	#include <algorithm>
	#include<queue>
	using namespace std;

	int main() {
		int n, len[100001], max=0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> len[i];
		sort(len+1, len+n+1);

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			q.push(len[i]);
		}

		for (int i = 1; i <= n; i++) {
			if ((n - i + 1)*q.front() > max) max = (n - i + 1)*q.front();
			q.pop();
		}

		cout << max;
	}
