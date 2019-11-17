#include <iostream>

using namespace std;

char map[100][100];
char newmap[100][100];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            char rot;
            if(map[i][j]=='-') rot = '|';
            else if(map[i][j]=='|') rot='-';
            else if(map[i][j]=='/') rot='\\';
            else if(map[i][j]=='\\') rot='/';
            else if(map[i][j]=='^') rot='<';
            else if(map[i][j]=='<') rot='v';
            else if(map[i][j]=='v') rot='>';
            else if(map[i][j]=='>') rot='^';
            else rot = map[i][j];
            newmap[m-1-j][i] = rot;
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout << newmap[i][j];
        }
        cout << endl;
    }

    return 0;
}