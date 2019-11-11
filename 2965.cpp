#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int dis = max(c - b, b - a);
	cout << dis - 1;

	return 0;
}