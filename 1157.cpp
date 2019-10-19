#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	int arr[26] = { 0, };
	int maxv = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 'Z' && str[i] <= 'z') str[i] -= 32;
		arr[str[i] - 'A']++;
		maxv = max(maxv, arr[str[i] - 'A']);
	}
	char res = '1';
	for (int i = 0; i < 26; i++) {
		if (res=='1' && arr[i] == maxv) res = 'A' + i;
		else if (res != '1' && arr[i] == maxv) {
			res = '?';
			break;
		}
	}
	cout << res;
	

	return 0;
}