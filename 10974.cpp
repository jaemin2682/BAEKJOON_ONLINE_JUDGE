#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> list;
	for (int i = 1; i <= n; i++) list.push_back(i);
	
	do {
		for (int i = 0; i < list.size(); i++) printf("%d ", list[i]);
		printf("\n");
	} while (next_permutation(list.begin(), list.end()));

	return 0;
}