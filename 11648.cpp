#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt = 0;
    while (1) {
        if(str.size() == 1) break;
        int rem = 1;
        for (int i = 0; i < str.size(); i++) {
            rem *= str[i]-48;
        }
        str = to_string(rem);
        cnt++;
    }
    cout << cnt;

    return 0;
}