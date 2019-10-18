#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int k;
string arr[30];

void dfs(int pos, string str, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i<str.size(); i++) {
			cout << str[i];// << " ";
		}
		cout << endl;
		return;
	}
	for (int i = pos; i < k; i++) {
		dfs(i + 1, str + arr[i] + ' ', cnt + 1);
	}
}


int main() {

	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		dfs(0, "", 0);
		cout << endl;
	}


	return 0;
}