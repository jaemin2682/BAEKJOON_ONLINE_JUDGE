#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

vector<vector<int>> map(101);
bool visit[101];
int n;

void dfs(int start, bool check) {
	if(!check) visit[start] = true;
	check = false;
	for (int i = 0; i < map[start].size(); i++) {
		int next = map[start][i];
		if (!visit[next]) {
			dfs(next, check);
		}
	}
}

int main() {
	
	cin >> n;
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if(a==1) map[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool check = false;
			if (i == j) check = true;
			dfs(i, check);
			if (visit[j]) cout << "1 ";
			else cout << "0 ";
			memset(visit, false, sizeof(visit));
		}
		cout << endl;
	}

	return 0;
}