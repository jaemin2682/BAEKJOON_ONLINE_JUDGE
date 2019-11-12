#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	vector<int> list(4);
	cin >> list[0] >> list[1] >> list[2] >> list[3];
	sort(list.begin(), list.end());
	cout << (list[0]) * (list[2]);

	return 0;
}