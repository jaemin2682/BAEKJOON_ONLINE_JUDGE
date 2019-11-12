#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int ioi = 0, joi = 0;
	if (str.size() == 1 || str.size() == 2) cout << joi << endl << ioi;
	else {
		for (int i = 0; i < str.size() - 2; i++) {
			if (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') joi++;
			if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') ioi++;
		}
		cout << joi << endl << ioi;
	}

	return 0;
}