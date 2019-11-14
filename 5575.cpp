#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int starth, startm, starts, endh, endm, ends;
		bool up = false;
		cin >> starth >> startm >> starts >> endh >> endm >> ends;
		int couts, coutm, couth;

		if (ends - starts < 0) {
			couts = ends - starts + 60;
			up = true;
		}
		else couts = ends - starts;

		if (endm - startm - up < 0) {
			coutm = endm - startm - up + 60;
			up = true;
		}
		else {
			coutm = endm - startm - up;
			up = false;
		}

		couth = endh - starth - up;

		cout << couth << " " << coutm << " " << couts << endl;
	}

	return 0;
}