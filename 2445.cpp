#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 2, cnt1 = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < cnt1; j++) cout << '*';
		for (int j = 0; j < n*2 - cnt; j++) cout << ' ';
		for (int j = 0; j < cnt1; j++) cout << '*';
		cout << endl;
		cnt += 2;
		cnt1++;
	}
	cnt1 = n - 1;
	cnt = 2;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < cnt1; j++) cout << '*';
		for (int j = 0; j < cnt; j++) cout << ' ';
		for (int j = 0; j < cnt1; j++) cout << '*';
		cout << endl;
		cnt1--;
		cnt += 2;
	}

	return 0;
}