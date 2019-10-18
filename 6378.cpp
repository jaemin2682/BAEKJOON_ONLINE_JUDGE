#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	while (1) {
		string str;
		cin >> str;
		if (str == "0") break;
		
		while (str.size() != 1) {
			int sum = 0;
			for (int i = 0; i < str.size(); i++) {
				sum += str[i] - 48;
			}
			str = to_string(sum);
		}
		cout << str << endl;
	}
	return 0;
}