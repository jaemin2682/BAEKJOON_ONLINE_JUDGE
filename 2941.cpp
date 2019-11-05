#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;
	int cnt = 0;

	while (str.size()) {
		if (str[0] == 'c' && (str[1] == '=' || str[1] == '-')) {
			str.erase(str.begin(), str.begin() + 2);
			cnt++;
		}

		else if (str[0] == 'd' && str[1] == 'z' && str[2] == '=') {
			str.erase(str.begin(), str.begin() + 3);
			cnt++;
		}

		else if ((str[0] == 'd' && str[1] == '-') || (str[0] == 'l' && str[1] == 'j') || (str[0] == 'n' && str[1] == 'j')
			|| (str[0] == 's' && str[1] == '=') || (str[0] == 'z' && str[1] == '=')) {
			str.erase(str.begin(), str.begin() + 2);
			cnt++;
		}

		else {
			str.erase(str.begin(), str.begin() + 1);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}