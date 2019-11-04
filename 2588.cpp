#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int one = a[2] - 48;
	cout << (b[2] - 48) * stoi(a) << endl;
	cout << (b[1] - 48) * stoi(a) << endl;
	cout << (b[0] - 48) * stoi(a) << endl;
	cout << stoi(a) * stoi(b);
	return 0;
}