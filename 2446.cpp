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
	int cnt = 2*n-1, cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < cnt1; j++) cout << ' ';
		for (int j = 0; j < cnt; j++) cout << '*';
		cout << endl;
		cnt -= 2;
		cnt1++;
	}
	
	cnt1 = n - 2;
	cnt = 3;
	for (int i = 0; i < n-1 ; i++) {
		for (int j = 0; j < cnt1; j++) cout << ' ';
		for (int j = 0; j < cnt; j++) cout << '*';
		cout << endl;
		cnt1--;
		cnt += 2;
	}
	
	return 0;
}