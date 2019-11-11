#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int maxscore = 0, index;
	for (int i = 0; i < 5; i++) {
		int score1, score2, score3, score4;
		cin >> score1 >> score2 >> score3 >> score4;
		int sum = score1 + score2 + score3 + score4;
		if (maxscore < sum) {
			maxscore = sum;
			index = i + 1;
		}
	}
	cout << index << " " << maxscore;

	return 0;
}