#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

bool sorter(string a, string b) {
	if (a.size() < b.size()) return true;
	else if(a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) continue;
			else if (a[i] < b[i]) return true;
			else return false;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<string> strlist;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		strlist.push_back(str);
	}
	sort(strlist.begin(), strlist.end(), sorter);
	strlist.erase(unique(strlist.begin(), strlist.end()), strlist.end());
	
	
	for (int i = 0; i < strlist.size(); i++) cout << strlist[i] << endl;
	return 0;
}

