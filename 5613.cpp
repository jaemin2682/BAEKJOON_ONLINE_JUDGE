#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int ans = 0, tem;
	string rem;
	while (1) {
		string cal;
		cin >> cal;
		if (cal == "=") {
			cout << ans;
			return 0;
		}

		if (cal == "+" || cal == "-" || cal == "*" || cal == "/") rem = cal;
		else {
			tem = stoi(cal);
			if (rem == "+") ans += tem;
			else if (rem == "-") ans -= tem;
			else if (rem == "*") ans *= tem;
			else if (rem == "/") ans /= tem;
			else ans = tem;
		}
	}

	return 0;
}