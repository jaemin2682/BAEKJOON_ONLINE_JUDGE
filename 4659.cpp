#include <iostream>
#include <string>
using namespace std;

int main() {
	while (1) {
		string str;
		cin >> str;
		if (str == "end") break;
		bool check = false;
		bool check1 = true;
		bool check2 = true;
		int ja = 0;
		int mo = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				check = true;
			}
			
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				mo++;
				ja = 0;
			}
			else {
				ja++;
				mo = 0;
			}
			if (ja == 3 || mo == 3) {
				check2 = false;
				break;
			}
			
			if (str.size() >= 2) {
				if (i < str.size() - 1) {
					if (str[i] == str[i + 1]) {
						if (str[i] == 'e' || str[i] == 'o') continue;
						else {
							check1 = false;
							break;
						}
					}
				}
			}
		}
		
		cout << "<" << str << ">" << " is ";
		if (!check1 || !check2 || !check) cout << "not ";
		cout << "acceptable." << endl;

		
	}
	return 0;
}