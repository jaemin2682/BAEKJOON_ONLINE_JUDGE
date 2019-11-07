#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	sort(str.begin(), str.end(), greater<int>());
	cout << str;

	return 0;
}

