#include <iostream>
#include <string>
using namespace std;

string str;
int n, m;

int gcd(int a, int b) {
    if(a<b) swap(a, b); //a가 더 크게 만들어줌
    while(b!=0) {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    int idx = str.find(':');    //파싱 분기점 찾음
    string prev = str.substr(0, idx), post = str.substr(idx+1, str.size()); //파싱
    int prev_n = stoi(prev), post_n = stoi(post);
    int gcd_val = gcd(prev_n, post_n);

    cout << prev_n/gcd_val << ":" << post_n/gcd_val;
    return 0;
}
// 그냥 두 수를 분자, 분모라 생각하고 최대한 약분하여 출력하면 된다.