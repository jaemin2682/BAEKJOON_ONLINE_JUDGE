#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int n, cnt;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    map<int, int> orikey;
    for(int i=1;i<10;i++) {
        int a;
        cin >> a;
        orikey[a] = i;
    }
    string str;
    cin >> str;
    str += " ";
    int strSize = str.size();
    for(int i=0;i<strSize;i++) {
        if(str[i] =='a' || str[i]=='b' || str[i]=='c') {
            if(str[i] == 'a') cout << orikey[2];
            else if(str[i] == 'b') cout << orikey[2] << orikey[2];
            else if(str[i] == 'c') cout << orikey[2] << orikey[2] << orikey[2];
            if(str[i+1] =='a' || str[i+1]=='b' || str[i+1]=='c') cout << '#';
        }
        else if(str[i] =='d' || str[i]=='e' || str[i]=='f') {
            if(str[i] == 'd') cout << orikey[3];
            else if(str[i] == 'e') cout << orikey[3] << orikey[3];
            else if(str[i] == 'f') cout << orikey[3] << orikey[3] << orikey[3];
            if(str[i+1] =='d' || str[i+1]=='e' || str[i+1]=='f') cout << '#';
        }
        else if(str[i] =='g' || str[i]=='h' || str[i]=='i') {
            if(str[i] == 'g') cout << orikey[4];
            else if(str[i] == 'h') cout << orikey[4] << orikey[4];
            else if(str[i] == 'i') cout << orikey[4] << orikey[4] << orikey[4];
            if(str[i+1] =='g' || str[i+1]=='h' || str[i+1]=='i') cout << '#';
        }
        else if(str[i] =='j' || str[i]=='k' || str[i]=='l') {
            if(str[i] == 'j') cout << orikey[5];
            else if(str[i] == 'k') cout << orikey[5] << orikey[5];
            else if(str[i] == 'l') cout << orikey[5] << orikey[5] << orikey[5];
            if(str[i+1] =='j' || str[i+1]=='k' || str[i+1]=='l') cout << '#';
        }
        else if(str[i] =='m' || str[i]=='n' || str[i]=='o') {
            if(str[i] == 'm') cout << orikey[6];
            else if(str[i] == 'n') cout << orikey[6] << orikey[6];
            else if(str[i] == 'o') cout << orikey[6] << orikey[6] << orikey[6];
            if(str[i+1] =='m' || str[i+1]=='n' || str[i+1]=='o') cout << '#';
        }
        else if(str[i] =='p' || str[i]=='q' || str[i]=='r' || str[i]=='s') {
            if(str[i] == 'p') cout << orikey[7];
            else if(str[i] == 'q') cout << orikey[7] << orikey[7];
            else if(str[i] == 'r') cout << orikey[7] << orikey[7] << orikey[7];
            else if(str[i] == 's') cout << orikey[7] << orikey[7] << orikey[7] << orikey[7];
            if(str[i+1] =='p' || str[i+1]=='q' || str[i+1]=='r' || str[i+1]=='s') cout << '#';
        }
        else if(str[i] =='t' || str[i]=='u' || str[i]=='v') {
            if(str[i] == 't') cout << orikey[8];
            else if(str[i] == 'u') cout << orikey[8] << orikey[8];
            else if(str[i] == 'v') cout << orikey[8] << orikey[8] << orikey[8];
            if(str[i+1] =='t' || str[i+1]=='u' || str[i+1]=='v') cout << '#';
        }
        else if(str[i] =='w' || str[i]=='x' || str[i]=='y' || str[i]=='z') {
            if(str[i] == 'w') cout << orikey[9];
            else if(str[i] == 'x') cout << orikey[9] << orikey[9];
            else if(str[i] == 'y') cout << orikey[9] << orikey[9] << orikey[9];
            else if(str[i] == 'z') cout << orikey[9] << orikey[9] << orikey[9] << orikey[9];
            if(str[i+1] =='w' || str[i+1]=='x' || str[i+1]=='y' || str[i+1]=='z') cout << '#';
        }
    }
    cout << '\n';

    return 0;
}
/*
어렵지 않은 문자열 구현 문제였으나, 노동강도가 강했다.
*/