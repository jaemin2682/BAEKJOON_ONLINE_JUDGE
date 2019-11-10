#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int blankcnt = n - 1;
	int starcnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < blankcnt; j++) cout << ' ';
		for (int j = 0; j < starcnt; j++) cout << "* ";
		blankcnt--;
		starcnt++;
		cout << endl;
	}

	return 0;
}

