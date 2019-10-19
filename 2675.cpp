#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int r;
		string str;
		cin >> r >> str;

		for (int j = 0; j < str.size(); j++) {
			for (int a = 0; a < r; a++) {
				cout << str[j];
			}
		}
		cout << endl;
	}
	return 0;
}