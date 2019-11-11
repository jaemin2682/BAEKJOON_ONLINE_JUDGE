#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (str[i] + 13 > 'Z') str[i] -= 26;
			str[i] = str[i] + 13;
			
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] + 13> 'z') str[i] -= 26;
			str[i] = str[i] + 13;
			
		}
	}
	cout << str;

	return 0;
}