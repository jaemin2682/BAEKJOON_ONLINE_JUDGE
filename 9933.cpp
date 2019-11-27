#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int n;
string str;
map<string, int> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> str;
        m.insert({str, i});
        reverse(str.begin(), str.end());
        if(m.find(str) != m.end()) {
            int size = str.size();
            cout << size << " " << str[size/2];
        }
    }
    return 0;
}
/*
map을 활용하여 빠르게 탐색을 할 수 있도록 했다.
*/