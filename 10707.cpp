#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int main() {
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int Xcom = p * a;
	int Ycom;
	if (p <= c) Ycom = b;
	else Ycom = (p - c)*d + b;
	
	if (Xcom > Ycom) cout << Ycom;
	else cout << Xcom;

	return 0;
}