#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int month, day;
	cin >> month >> day;
	if (month > 2) cout << "After";
	else if (month < 2) cout << "Before";
	else {
		if (day > 18) cout << "After";
		else if (day < 18) cout << "Before";
		else cout << "Special";
	}
	return 0;
}