#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;
	int stack = 0;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			cnt += stack;
			i++; continue;
		}
		else if (str[i] == '(') stack++;
		else if (str[i] == ')') {
			stack--; cnt++;
		}
	}
	cout << cnt;

	return 0;
}