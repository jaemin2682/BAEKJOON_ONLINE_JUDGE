#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> list;
	for(int i=0;i<9;i++) {
		int a;
		cin >> a;
		list.push_back(a);
	}
	int max = 0, ind;
	for (int i = 0; i < 9; i++) {
		if (list[i] > max) {
			max = list[i];
			ind = i;
		}
	}
	cout << max << endl << ind+1;


	return 0;
}