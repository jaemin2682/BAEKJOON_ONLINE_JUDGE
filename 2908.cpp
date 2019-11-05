#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	char tem;
	tem = a[0];
	a[0] = a[2];
	a[2] = tem;
	tem = b[0];
	b[0] = b[2];
	b[2] = tem;

	if (stoi(a) > stoi(b)) cout << a;
	else cout << b;
	
	return 0;
}