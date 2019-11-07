#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;


int main() {
	int n, ans=0;
	cin >> n;
	for (int i = 666; i < 21474836476; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.size()-2; j++) {
			if (str[j] == '6' && str[j + 1] == '6' && str[j + 2] == '6') {
				ans++;
				if (ans == n) {
					cout << i;
					return 0;
				}
				break;
			}
		}
	}

	return 0;
}

