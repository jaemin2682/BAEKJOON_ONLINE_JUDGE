#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	vector<pair<int, int>> move;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		move.push_back({ a, b });
	}
	vector<pair<int, int>> arr(4);
	for (int i = 1; i <= 3; i++) {
		arr[i].first = i;
		arr[i].second = i;
	}
	for (int i = 0; i < m; i++) {
		int temp = arr[move[i].first].second;
		arr[move[i].first].second = arr[move[i].second].second;
		arr[move[i].second].second = temp;
	}
	int ans;
	for (int i = 1; i <= 3; i++)
		if (arr[i].second == 1) ans = arr[i].first;

	printf("%d", ans);
	return 0;
}