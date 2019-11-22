#include <iostream>
#include <string>

using namespace std;

int main() {
    while(1) {
        char alpha;
        string str;
        int cnt=0;
        cin >> alpha;
        if(alpha == '#') break;
        getline(cin, str);

        for(int i=0;i<str.size();i++) 
            if(str[i] == alpha || str[i] == alpha-32) cnt++;
        
        cout << alpha << " " << cnt << endl;
    }

    return 0;
}
/*
문제 재해석이 필요 없는 문제
*/