#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	vector<int> queue;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			queue.push_back(num);
		}
		else if (str == "pop") {
			if (queue.empty()) cout << -1 << endl;
			else {
				cout << queue[0] << endl;
				queue.erase(queue.begin());
			}
		}
		else if (str == "size") {
			cout << queue.size() << endl;
		}
		else if (str == "empty") {
			if (queue.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (str == "front") {
			if (queue.empty()) cout << -1 << endl;
			else cout << queue[0] << endl;
		}
		else if (str == "back") {
			if (queue.empty()) cout << -1 << endl;
			else cout << queue[queue.size() - 1] << endl;
		}
	}

	return 0;
}