#include <iostream>
#include <string>
using namespace std;

int Lpinky, Lring, Lmiddle, Lindex, Rindex, Rmiddle, Rring, Rpinky;
string str;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    int size = str.size();
    for(int i=0;i<size;i++) {
        if(str[i] == '1' || str[i] == 'Q' || str[i] == 'A' || str[i] == 'Z') Lpinky++;
        else if(str[i] == '2' || str[i] == 'W' || str[i] == 'S' || str[i] == 'X') Lring++;
        else if(str[i] == '3' || str[i] == 'E' || str[i] == 'D' || str[i] == 'C') Lmiddle++;
        else if(str[i] == '4' || str[i] == '5' || str[i] == 'R' || str[i] == 'T'
        || str[i] == 'F' || str[i] == 'G' || str[i] == 'V'|| str[i] == 'B') Lindex++;
        else if(str[i] == '6' || str[i] == '7' || str[i] == 'Y' || str[i] == 'U'
        || str[i] == 'H' || str[i] == 'J' || str[i] == 'N'|| str[i] == 'M') Rindex++;
        else if(str[i] == '8' || str[i] == 'I' || str[i] == 'K' || str[i] == ',') Rmiddle++;
        else if(str[i] == '9' || str[i] == 'O' || str[i] == 'L' || str[i] == '.') Rring++;
        else Rpinky++;
    }

    cout << Lpinky << endl << Lring << endl << Lmiddle << endl << Lindex << endl <<
    Rindex << endl << Rmiddle << endl << Rring << endl << Rpinky;

    return 0;
}
// 그저 노가다 문제였다... 눈아프다