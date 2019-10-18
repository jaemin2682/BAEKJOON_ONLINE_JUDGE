#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
vector<int> vec12;
vector<int> vec16;

int to_10(int num) {
	string str = to_string(num);
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += str[i] - 48;
	}
	return sum;
}

int to_12(int num) { 
	while (num >= 12) {
		vec12.push_back(num % 12);
		num /= 12;
	}
	vec12.push_back(num);

	int sum = 0;
	for (int i = 0; i < vec12.size(); i++) sum += vec12[i];
	vec12.erase(vec12.begin(), vec12.end());
	return sum;
}

int to_16(int num) {
	while (num >= 16) {
		vec16.push_back(num % 16);
		num /= 16;
	}
	vec16.push_back(num);

	int sum = 0;
	for (int i = 0; i < vec16.size(); i++) sum += vec16[i];
	vec16.erase(vec16.begin(), vec16.end());
	return sum;
}

int main() {
	for(int i=1000;i<10000;i++) {
		if ((to_10(i) == to_12(i)) && (to_12(i) == to_16(i))) {
			cout << i << endl;
		}
	}

	return 0;
}