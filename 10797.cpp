#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int num, cnt=0;
	cin >> num;
	for (int i = 0; i < 5; i++) {
		int car;
		cin >> car;
		if (num == car) cnt++;
	}
	cout << cnt;

	return 0;
}