#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	int tem, cnt=0;
	int res = num;	
	do {
		if (num >= 10) tem = num / 10 + num % 10;	
		else tem = num;

		if (tem >= 10) tem %= 10;		

		num = (num % 10) * 10 + tem;	
		cnt++; 
	} while (res != num);

	cout << cnt;


	return 0;
}