#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, Ascore = 0, Bscore = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			char A, B;
			cin >> A >> B;
			if (A == 'R') {
				if (B == 'P') Bscore++;
				else if (B == 'S') Ascore++;
			}
			else if (A == 'P') {
				if (B == 'R') Ascore++;
				else if (B == 'S') Bscore++;
			}
			else {
				if (B == 'R') Bscore++;
				else if (B == 'P') Ascore++;
			}
		}
		if (Ascore > Bscore) cout << "Player 1" << endl;
		else if (Ascore < Bscore) cout << "Player 2" << endl;
		else cout << "TIE" << endl;
 	}
	return 0;
}