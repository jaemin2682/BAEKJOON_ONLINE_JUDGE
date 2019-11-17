#include <iostream>
#include <string>

using namespace std;

int main() {
    int p;
    cin >> p;
    for(int i=0;i<p;i++) {
        string str;
        cin >> str; //back : T, front : H
        int ttt=0, tth=0, tht=0, thh=0, htt=0, hth=0, hht=0, hhh=0;
        for(int j=0;j<str.size()-2;j++) {
            if(str[j]=='T' && str[j+1]=='T' && str[j+2] == 'T') ttt++;
            else if(str[j]=='T' && str[j+1]=='T' && str[j+2] == 'H') tth++;
            else if(str[j]=='T' && str[j+1]=='H' && str[j+2] == 'T') tht++;
            else if(str[j]=='T' && str[j+1]=='H' && str[j+2] == 'H') thh++;
            else if(str[j]=='H' && str[j+1]=='T' && str[j+2] == 'T') htt++;
            else if(str[j]=='H' && str[j+1]=='T' && str[j+2] == 'H') hth++;
            else if(str[j]=='H' && str[j+1]=='H' && str[j+2] == 'T') hht++;
            else if(str[j]=='H' && str[j+1]=='H' && str[j+2] == 'H') hhh++;
        }
        cout << ttt << " " << tth << " " << tht << " " << thh << " " << htt << " " <<hth
        << " " << hht << " " << hhh << endl;
    }

    return 0;
}