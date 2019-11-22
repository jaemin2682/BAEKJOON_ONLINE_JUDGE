#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        vector<char> card(n);
        string ans;
        for(int i=0;i<n;i++) cin >> card[i];
        
        ans += card[0];
        for(int i=1;i<n;i++) {
            if(card[i] <= ans[0]) ans.insert(ans.begin(), card[i]);
            else ans += card[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}
/*
첫 문자는 바로 답안에 추가하고, 다음 문자부터 가장 앞 단어보다 빠르면 앞에,
느리면 뒤에 추가한다.
*/