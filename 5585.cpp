#include <iostream>
#include <string>
using namespace std;

int main() {
	int cost, cnt=0;
	cin >> cost;

	cost = 1000 - cost;
	while (cost != 0) {
		if (cost >= 500) {
			cost -= 500;
			cnt++;
		}
		else if (cost >= 100) {
			cost -= 100;
			cnt++;
		}
		else if (cost >= 50) {
			cost -= 50;
			cnt++;
		}
		else if (cost >= 10) {
			cost -= 10;
			cnt++;
		}
		else if (cost >= 5) {
			cost -= 5;
			cnt++;
		}
		else if (cost >= 1) {
			cost -= 1;
			cnt++;
		}
	}

	cout << cnt;
}