#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int up, middle, down, cola, sidar, bugercheap, drinkcheap;
	cin >> up >> middle >> down >> cola >> sidar;
	
	bugercheap = min(up, middle);
	bugercheap = min(bugercheap, down);

	drinkcheap = min(cola, sidar);

	cout << bugercheap + drinkcheap - 50;

	return 0;
}


