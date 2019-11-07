#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	vector<pair<int, int>> list;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		list.push_back({ y, x });
	}
	
	sort(list.begin(), list.end());
	
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", list[i].second, list[i].first);
	}

	return 0;
}

