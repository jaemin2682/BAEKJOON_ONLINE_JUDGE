#include <iostream>
#include <math.h>

using namespace std;

char puzzle[4][4];

int main() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cin >> puzzle[i][j];
        }
    }
    int scat=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(puzzle[i][j]!='.') {
                scat += abs(i - (puzzle[i][j]-'A')/4) + abs(j-(puzzle[i][j]-'A')%4);
            }
        }
    }
    cout << scat;

// [(puzzle[i][j]-'A')/4][(puzzle[i][j]-'A')%4]
    return 0;
}
