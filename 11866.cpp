#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> list(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) list[i] = i+1;
	k -= 1;
	int index = k;
	while (!list.empty()) {
		ans.push_back(list[k]);
		list.erase(list.begin() + k);
		if(!list.empty())	k = (k + index) % (list.size());
	}
	cout << "<";
	for (int i = 0; i < n-1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[n - 1] << ">";

	return 0;
}