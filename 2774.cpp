#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string x;
		cin >> x;
		set<int> s;
		for (int j = 0; j < x.size(); j++) {
			s.insert(x[j]);
		}
		cout << s.size() << endl;
	}
	return 0;
}