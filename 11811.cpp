#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int n;
int arr[1000][1000];
int answer[1000];

int main() {
	

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			answer[i] |= arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}


	return 0;
}