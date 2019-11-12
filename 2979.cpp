#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int Car[101];

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int i = start; i < end; i++) Car[i]++;
	}
	int price = 0;
	for (int i = 1; i <= 100; i++) {
		if (Car[i] == 1) price += 1 * a;
		else if (Car[i] == 2) price += 2 * b;
		else if (Car[i] == 3) price += 3 * c;
	}
	cout << price;
	return 0;
}