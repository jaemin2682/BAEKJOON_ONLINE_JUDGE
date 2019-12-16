#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string music;
int gacnt, dacnt;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> music;

    int musicSize = music.size();
    bool da = true;
    for(int i=0;i<musicSize;i++) {
        if(i==0) {
            if(music[i] == 'A' || music[i] == 'D' || music[i] == 'E') gacnt++;
            else if(music[i] == 'C' || music[i] == 'F' || music[i] == 'G') dacnt++;
        }
        if(music[i] == '|') {
            if(music[i+1] == 'A' || music[i+1] == 'D' || music[i+1] == 'E') gacnt++;
            else if(music[i+1] == 'C' || music[i+1] == 'F' || music[i+1] == 'G') dacnt++;
        }
    }
    if(music[musicSize-1]=='C'||music[musicSize-1]=='F'
    ||music[musicSize-1]=='G') da = true;
    else da = false;

    if(gacnt > dacnt) cout << "A-minor";
    else if(gacnt < dacnt) cout << "C-major";
    else {
        if(da) cout << "C-major";
        else cout << "A-minor";
    }
    return 0;
}
/*
문제의 요구만 정확히 구현하면 되는 문제였다. 어렵지는 않았다.
*/