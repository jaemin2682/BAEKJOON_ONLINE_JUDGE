#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int fibonachi(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibonachi(n - 1) + fibonachi(n - 2);
}


int main() {
	int n;
	cin >> n;
	cout << fibonachi(n);
	return 0;
}

