#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int arr[5];
	int l, p;
	cin >> l >> p;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	int area = l * p;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] - area<< " ";
	}

	return 0;
}