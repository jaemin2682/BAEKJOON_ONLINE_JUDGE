#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
// a : 97, z:122
int main() {

	int n, cnt=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		bool visit[30];
		memset(visit, false, 30);
		cin >> str;
		str += ' ';
		for (int j = 0; j < str.size()-1; j++) {
			if (visit[str[j] - 97]) {
				cnt++;
				break;
			}
			if (str[j] != str[j + 1]) visit[str[j] - 97] = true;
		}
	}
	
	cout << n - cnt;

	return 0;
}