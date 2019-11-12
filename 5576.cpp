#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	vector<int> teamA(10);
	vector<int> teamB(10);

	for (int i = 0; i < 10; i++) cin >> teamA[i];
	for (int i = 0; i < 10; i++) cin >> teamB[i];
	
	sort(teamA.begin(), teamA.end(), greater<int>());
	sort(teamB.begin(), teamB.end(), greater<int>());

	cout << teamA[0] + teamA[1] + teamA[2] << " ";
	cout << teamB[0] + teamB[1] + teamB[2];

	return 0;
}