#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>


using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num, cnt=0;
		cin >> num;
		int three=0, two=0;
		for (three = 0; 3*three <= num; three++) {
			for (two = 0; 2*two <= num; two++) {
				vector<int> list;
				for (int a = 0; a < three; a++) list.push_back(3);
				for (int b = 0; b < two; b++) list.push_back(2);
				int sum = three * 3 + two * 2;
				if (sum > num) continue;
				while (sum != num) {
					list.push_back(1);
					sum++;
				}
				sort(list.begin(), list.end());
				do { 
					cnt++; 
				} while (next_permutation(list.begin(), list.end()));
			}
		}
		cout << cnt << endl;
	}

	return 0;
}


