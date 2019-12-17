#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

string a, b, c, d;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    string num1 = a + b;
    string num2 = c + d;
    long long ans = stoll(num1) + stoll(num2); //string -> long long
    cout << ans;    
    return 0;
}
/*
string으로 이어붙이고 stoll를 통해 long long형으로 바꿔주어 풀었다.
*/