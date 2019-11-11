#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	string str;
	vector<string> list;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		string temp = "";
		for (int j = i; j < str.size(); j++) {
			temp += str[j];
		}
		list.push_back(temp);
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) cout << list[i] << endl;

	return 0;
}