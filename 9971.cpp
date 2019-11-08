#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	string str;
	string message;
	while (1) {
		cin >> str;
		if (str == "START") {
			cin.ignore();
			getline(cin, message);

			for (int i = 0; i < message.size(); i++) {
				if (message[i] >= 'A' && message[i] <= 'Z') {
					message[i] -= 5;
					if (message[i] < 'A') {
						message[i] = 'Z' - ('A' - message[i] - 1);
					}
				}
			}

			cout << message << endl;
		}
		else if (str == "END") continue;
		else if (str == "ENDOFINPUT") break;
		
	}

	return 0;
}

