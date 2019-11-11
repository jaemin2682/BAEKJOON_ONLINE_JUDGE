#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int main() {
	int k;
	stack<int> s;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0) s.pop();
		else s.push(num);
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}