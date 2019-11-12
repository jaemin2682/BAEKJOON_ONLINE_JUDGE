#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	while (1) {
		int man, woman;
		cin >> man >> woman;
		if (man == 0 && woman == 0) break;
		cout << man + woman << endl;
	}

	return 0;
}