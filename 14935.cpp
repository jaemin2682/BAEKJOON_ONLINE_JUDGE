#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, rem;
    cin >> str;
    while(str!=rem) {
        rem = str;
        int temp = str.size() * (str[0] - 48);
        str = to_string(temp);
    }
    cout << "FA";

    return 0;
}