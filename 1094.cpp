#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int main() {
	int x;
	string str = "";
	cin >> x;
	while (x!=1) {
		str.insert(0, to_string(x % 2));
		x /= 2;
	}
	str.insert(0, "1");

	int cnt = 0;
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '1') cnt++;
	cout << cnt;
	return 0;
}