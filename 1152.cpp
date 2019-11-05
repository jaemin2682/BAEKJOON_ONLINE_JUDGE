#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string str = "";
	string tem;
	int cnt = 0;
	getline(cin, str);
	
	if (str[0] == ' ') cnt--;
	if (str[str.size() - 1] == ' ') cnt--;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') cnt++;
	}

	cout << cnt+1;
	
	return 0;
}