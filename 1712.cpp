#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	double ans = A / (C - B);
	int tem = ans;
	if (B >= C) cout << -1;
	else {
		if (ans == tem) cout << tem+1;
		else cout << tem;
	}
	return 0;
}