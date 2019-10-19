#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (char alpha = 'a'; alpha <= 'z'; alpha++) {
		if (str.find(alpha) > 100) {
			cout << -1 << " ";
		}
		else cout << str.find(alpha) << " ";
	}
	return 0;
}