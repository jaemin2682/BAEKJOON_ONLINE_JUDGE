#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	
	string A, B;
	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '1' && B[i] == '1') cout << 1;
		else cout << 0;
	}
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '0' && B[i] == '0') cout << 0;
		else cout << 1;
	}
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != B[i]) cout << 1;
		else cout << 0;
	}
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '0') cout << 1;
		else cout << 0;
	}
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		if (B[i] == '0') cout << 1;
		else cout << 0;
	}

	return 0;
}