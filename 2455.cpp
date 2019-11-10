#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int out, in, maxnum=0;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		int people = maxnum - out + in;
		maxnum = max(maxnum, people);
	}
	cout << maxnum;
		
	
	return 0;
}