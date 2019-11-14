#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> score(n);
	vector<int> result(n);
	for (int i = 0; i < n; i++) result[i] = 0;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		score[i].push_back(a);
		score[i].push_back(b);
		score[i].push_back(c);
	}

	int scoreCheck[101];

	for (int i = 0; i < 3; i++) {
		memset(scoreCheck, 0, sizeof(scoreCheck));
		for (int j = 0; j < n; j++)	scoreCheck[score[j][i]]++;
		for (int j = 0; j < n; j++) {
			if (scoreCheck[score[j][i]] == 1) result[j] += score[j][i];
		}
	}

	for (int i = 0; i < n; i++) cout << result[i] << endl;


	return 0;
}