#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	while (1) {
		int H, D, F;
		double U;
		cin >> H >> U >> D >> F;
		if (H == 0) break;
		double MyHeight = 0;
		double CurU = U;
		bool check = true;
		int day = 1;
		while (1) {
			MyHeight += CurU;
			if (MyHeight > H) break;

			MyHeight -= D;
			if (MyHeight < 0) {
				check = false;
				break;
			}

			CurU -= U * ((double)F / 100);
			if (CurU <= 0) CurU = 0;
			day++;
		}
		
		if (check) cout << "success on day " << day << endl;
		else cout << "failure on day " << day << endl;

	}
	
	return 0;
}

