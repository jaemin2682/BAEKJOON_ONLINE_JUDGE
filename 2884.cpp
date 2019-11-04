#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	
	if (m - 45 < 0) {
		if (h == 0) h = 23;
		else h -= 1;
		m += 15;
	}
	else m -= 45;


	cout << h << " "<< m;

	return 0;
}