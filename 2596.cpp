#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<char, string>> v = {{'A', "000000"}, {'B', "001111"}, {'C', "010011"}, 
{'D', "011100"}, {'E', "100110"}, {'F', "101001"}, {'G', "110101"}, {'H', "111010"}};

int main() {
    int n, totalcnt=0, mincnt;
    string str, ans;
    cin >> n >> str;
    
    while(totalcnt!=n) {         //6개씩 끊어읽는 단위
        for(int a=0;a<8;a++) {  //벡터 안의 8가지 암호문
            int cnt=0;
            mincnt=7;
            for(int i=totalcnt*6,j=0 ;j<6; i++,j++) {    //각 암호문마다 6글자 비교
                if(str[i] != v[a].second[j]) cnt++; //다른 문자의 숫자를 센다.
            }
            mincnt = min(mincnt, cnt);  //최소 cnt를 저장
            if(cnt < 2) {   //2개 이하인 암호가 있으면 저장하고 끝낸다.
                ans += v[a].first;
                break;
            }
        }
        if(mincnt >= 2) {   //맞는 암호가 없으면 인덱스 출력하고 프로그램 종료
            cout << totalcnt+1;
            return 0;
        }
        totalcnt++;
    }

    cout << ans;    //종료된거 아니면 해독문 출력

    return 0;
}
/*
알파벳, 이진수를 pair로 담은 vector를 생성해 정보를 담아놓는다.
입력을 받고, 6자씩 끊어읽어 벡터의 원소 8가지에 대해 일일히 비교를 해본다.
틀린 자리수가 1 이하인 것이 있으면 저장해 놓았다가 출력, 2 이상인 경우가 나오면 출력하고 바로 끝낸다.

*/