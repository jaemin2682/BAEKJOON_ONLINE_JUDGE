#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<pair<int, int>, string>> list;
	for (int i = 0; i < n; i++) {
		int num;
		string str;
		scanf("%d", &num);
		cin >> str;
		list.push_back({ {num, i}, str });
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i].first.first);
		cout << list[i].second;
		printf("\n");
	}

	return 0;
}

