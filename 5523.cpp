#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n, Ascore = 0, Bscore = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) Ascore++;
		else if (a < b) Bscore++;
	}
	cout << Ascore << " " << Bscore;
	return 0;
}