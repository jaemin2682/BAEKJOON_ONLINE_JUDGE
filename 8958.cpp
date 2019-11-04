#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int t;
	string str;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int score = 0;
		int result = 0;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'O') score++;
			else score = 0;
			result += score;
		}
		cout << result << endl;
	}

	return 0;
}