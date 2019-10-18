#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		cout << "String #" << i + 1 << endl;
		for (int j = 0; j < str.size(); j++) {
			if ((str[j]) == 'Z') {
				cout << 'A';
			}
			else cout << (char)(str[j] + 1);
		}
		cout << endl << endl;
	}
	return 0;
}