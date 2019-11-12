#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int v, numA = 0, numB = 0;
	cin >> v;
	for (int i = 0; i < v; i++) {
		char a;
		cin >> a;
		if (a == 'A') numA++;
		else numB++;
	}
	if (numA > numB) cout << "A";
	else if (numA < numB) cout << "B";
	else cout << "Tie";

	return 0;
}