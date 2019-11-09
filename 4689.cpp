#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {

	while (1) {
		string str;
		int pre, post;
		cin >> str;
		if (cin.eof()) return 0;

		scanf("%d %d", &pre, &post);

		int decimal = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'A') decimal += (10) * pow(pre, str.size() - i - 1);
			else if (str[i] == 'B') decimal += (11) * pow(pre, str.size() - i - 1);
			else if (str[i] == 'C') decimal += (12) * pow(pre, str.size() - i - 1);
			else if (str[i] == 'D') decimal += (13) * pow(pre, str.size() - i - 1);
			else if (str[i] == 'E') decimal += (14) * pow(pre, str.size() - i - 1);
			else if (str[i] == 'F') decimal += (15) * pow(pre, str.size() - i - 1);
			else decimal += (str[i] - 48) * pow(pre, str.size() - i - 1);
		}
		string preval = "";
		int remain;
		int cnt = 1;
		if (decimal < post) preval = to_string(decimal);
		else {
			while (decimal >= post) {
				remain = decimal % post;
				decimal /= post;
				if (remain == 10) preval.insert(0, "A");
				else if (remain == 11) preval.insert(0, "B");
				else if (remain == 12) preval.insert(0, "C");
				else if (remain == 13) preval.insert(0, "D");
				else if (remain == 14) preval.insert(0, "E");
				else if (remain == 15) preval.insert(0, "F");
				else preval.insert(0, to_string(remain));
				if (decimal < post) {
					if (decimal == 10) preval.insert(0, "A");
					else if (decimal == 11) preval.insert(0, "B");
					else if (decimal == 12) preval.insert(0, "C");
					else if (decimal == 13) preval.insert(0, "D");
					else if (decimal == 14) preval.insert(0, "E");
					else if (decimal == 15) preval.insert(0, "F");
					else preval.insert(0, to_string(decimal));
				}
				cnt++;
				if (cnt > 7) {
					preval = "ERROR";
					break;
				}
			}
		}

		for (int i = 0; i < 7 - preval.size(); i++) printf(" ");
		cout << preval;
		printf("\n");
	}
	return 0;
}

