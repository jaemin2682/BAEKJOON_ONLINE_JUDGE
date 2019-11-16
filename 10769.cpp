#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	
	string str;
	getline(cin, str);
	int happy = 0, sad = 0;
	for (int i = 0; i < str.size() - 2; i++) {
		if (str[i] == ':' && str[i + 1] == '-' && str[i + 2] == ')') happy++;
		else if (str[i] == ':' && str[i + 1] == '-' && str[i + 2] == '(') sad++;
	}
	if (happy > sad) cout << "happy";
	else if (happy < sad) cout << "sad";
	else {
		if (happy == 0) cout << "none";
		else cout << "unsure";
	}

	return 0;
}