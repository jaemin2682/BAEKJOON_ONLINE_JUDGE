#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	while (1) {
		int num;
		cin >> num;
		if (num == -1) break;
		vector<int> arr;
		int sum = 0;
		for (int i = 1; i <= num / 2; i++)
			if (num%i == 0) {
				arr.push_back(i);
				sum += i;
			}
		if (sum == num) {
			cout << num << " = ";
			for (int i = 0; i < arr.size(); i++) {
				if (i == arr.size() - 1) cout << arr[i] << endl;
				else cout << arr[i] << " + ";
			}
		}
		else cout << num << " is NOT perfect." << endl;
	}

	return 0;
}