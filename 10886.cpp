#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n, agree=0, disagree=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num) agree++;
		else disagree++;
	}
	if (agree > disagree) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";

	return 0;
}

