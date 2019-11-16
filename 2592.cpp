#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int freq[101];

int main() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		sum += num;
		freq[num / 10]++;
	}
	int freqVal = 0, index = 0;
	for (int i = 1; i <= 100; i++) {
		if (freqVal < freq[i]) {
			freqVal = freq[i];
			index = i;
		}
	}
	cout << sum / 10 << endl << index * 10;

	return 0;
}