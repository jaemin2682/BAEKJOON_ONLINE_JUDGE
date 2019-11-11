#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num <= sqrt(w*w + h * h)) cout << "DA" << endl;
		else cout << "NE" << endl;
	}

	return 0;
}