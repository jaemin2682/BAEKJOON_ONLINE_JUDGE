#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int ine, ins, inm;
	cin >> ine >> ins >> inm;
	int e = 0, s = 0, m = 0;
	int year = 0;
	while (1) {
		if (e == 15) e = 1;
		else e++;
		if (s == 28) s = 1;
		else s++;
		if (m == 19) m = 1;
		else m++;
		year++;
		if (e == ine && s == ins && m == inm) break;
	}
	cout << year;
	
	return 0;
}