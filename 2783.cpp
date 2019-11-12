#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	double x25, y25, n;
	cin >> x25 >> y25;
	double lowprice = x25 / y25 * 1000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		double price = x / y * 1000;
		lowprice = min(lowprice, price);
	}
	printf("%.2f", lowprice);
	return 0;
}