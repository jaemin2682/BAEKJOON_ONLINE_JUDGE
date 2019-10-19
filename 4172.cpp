#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int list[5000003];
int eval(int num) {
	if (num == 0) {
		return 1;
	}
	int tem = floor(num - sqrt(num));
	int tem1 = floor(log(num));
	int tem2 = floor(num * pow(sin(num), 2));
	if (!list[tem]) list[tem] = eval(tem);
	if (!list[tem1]) list[tem1] = eval(tem1);
	if (!list[tem2]) list[tem2] = eval(tem2);
	list[num] = (list[tem] + list[tem1] + list[tem2]) % 1000000;
	return abs(list[num]);
}

int main() {
	while (1) {
		int i;
		cin >> i;
		if (i == -1) break;
		cout << eval(i) % 1000000 << endl;
	}
	return 0;
}