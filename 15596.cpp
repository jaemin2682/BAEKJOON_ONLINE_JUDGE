#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

long long sum(std::vector<int> &a) {
	long long ans;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
	}
	return ans;
}