#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	vector<int> arr;
	string tem = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			arr.push_back(stoi(tem));
			tem = "";
		}
		else {
			tem += str[i];
		}
	}
	arr.push_back(stoi(tem));
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	cout << sum;

	return 0;
}