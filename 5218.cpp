#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		cout << "Distances: ";
		for (int j = 0; j < str1.size(); j++) {
			if (str1[j] <= str2[j]) cout << str2[j] - str1[j] << " ";
			else cout << str2[j] + 26 - str1[j] << " ";
		}
		cout << endl;
	}

	return 0;
}