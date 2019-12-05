#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n, score;
map<string, int> hyunwoo;

string str;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<string> ans(n);
    for(int i=0;i<n;i++) cin >> ans[i];
    for(int i=0;i<n;i++) {
        cin >> str;
        hyunwoo.insert({str, i});
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(hyunwoo.find(ans[i])->second < hyunwoo.find(ans[j])->second) score++;
        }
    }

    cout << score << '/' << n*(n-1)/2;
    
   return 0;
}
/*
순서관계로의 전, 후가 answer배열과 맞는지 확인하는 문제이다.
2중포문으로 answer의 두 단어의 관계를 찾고, 현우의 답과 맞는지 확인한다.
이렇게 풀면 n^3인데, 최악으로는 2500*2500*2500 = 15,625,000,000번의 연산을 해야한다.
음.. 다른 방법을 찾자. 
MAP을 활용하여 순서를 바로 캐치하면 빠르게 찾을 수 있을 것 같다.
2중포문(O(n^2))로 두 단어의 관계를 찾고, 현우의 답과 확인을 O(1)만에 한다.

*/