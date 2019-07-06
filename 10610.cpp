#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]);
		sum += s[i] - 48;	
	}
	sort(v.begin(), v.end(), greater<int>());

	if (v.back()-48 != 0 || sum<3) cout << -1;
	else if (sum % 3 == 0) {
		for (int i = 0; i < s.length(); i++) cout << v[i]-48;
	}
	else cout << -1;
}