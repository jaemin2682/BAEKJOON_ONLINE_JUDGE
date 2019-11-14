#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string pre, post, prediction;
	cin >> pre >> post;
	for (int i = 0; i < pre.size(); i++) {
		if (pre[i] == '0') prediction += '1';
		else prediction += '0';
	}
	if (n % 2 == 0) {
		if (pre == post) cout << "Deletion succeeded";
		else cout << "Deletion failed";
	}
	else {
		if(prediction == post) cout << "Deletion succeeded";
		else cout << "Deletion failed";
	}

	return 0;
}