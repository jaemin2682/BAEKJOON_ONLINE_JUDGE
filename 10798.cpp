#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	vector<string> word;
	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		word.push_back(str);
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i > word[j].size() - 1) continue;
			cout << word[j][i];
		}
	}
	return 0;
}

