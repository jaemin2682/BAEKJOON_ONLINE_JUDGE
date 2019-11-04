#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	string str;
	int cnt = 0;
	cin >> str;
	for (int i = 1; i <= stoi(str); i++) {
		string tem = to_string(i);
		if (tem.size() == 1 && tem.size() == 2) cnt++;
		else {
			bool check = true;
			int dif = tem[0] - tem[1];
			for (int j = 1; j < tem.size()-1; j++) {
				if (tem[j] - tem[j + 1] != dif) check = false;
			}
			if (check) cnt++;
		}
	}
	cout << cnt;
	

	return 0;
}