#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>


using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	int day;
	double day1 = (double)(v - b) / (double)(a - b);
	day = (v - b) / (a - b);
	if (day != day1) day++;

	cout << day;
	return 0;
}


