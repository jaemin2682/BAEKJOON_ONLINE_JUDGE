#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cntblank = n-1, cntMiddleblank = -1;
	for (int i = 0; i < n-1 ; i++) {
		for (int a = 0; a < cntblank; a++) cout << ' ';
		cout << '*';
		for (int b = 0; b < cntMiddleblank; b++) cout << ' ';
		if(i!=0) cout << '*';
		cntblank--;
		cntMiddleblank += 2;
		cout << endl;
	}
	for (int i = 0; i < n * 2 - 1; i++) cout << '*';

	return 0;
}