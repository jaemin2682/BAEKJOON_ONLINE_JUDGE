#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
    int Casenum = 1;
    while(1) {
        string pre, post;
        cin >> pre >> post;
        if(pre=="END" && post=="END") break;
        int alpha[26], alphapost[26];
        memset(alpha, 0, sizeof(alpha));
        memset(alphapost, 0, sizeof(alphapost));

        for(int i=0;i<pre.size();i++) alpha[pre[i]-'a']++;
        for(int i=0;i<post.size();i++) alphapost[post[i]-'a']++;
        bool check = true;
        for(int i=0;i<26;i++) {
            if(alpha[i] != alphapost[i]) {
                check = false;
                break;
            }
        }
        cout << "Case " << Casenum << ": ";
        if(check) cout << "same" << endl;
        else cout << "different" << endl;

        Casenum++;
    }

    return 0;
}