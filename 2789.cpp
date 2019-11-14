#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	string str;
	vector<int> eralist;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' ||
			str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E') eralist.push_back(i);
	}
	
	for (int i = eralist.size() - 1; i >= 0; i--) str.erase(str.begin() + eralist[i]);
	cout << str;

	
	return 0;
}