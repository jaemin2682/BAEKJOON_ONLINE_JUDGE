#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int res = a * b * c;
	string str = to_string(res);
	int arr[11] = { 0, };
	for (int i = 0; i < str.size(); i++) {
		arr[str[i]-'0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}


	return 0;
}