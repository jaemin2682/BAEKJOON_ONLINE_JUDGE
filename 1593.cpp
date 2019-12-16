#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int g, s;
int cnt;
int alphabet[52]; //0~25 : 대문자, 26~51:소문자
int alphabetS[52];
string W, S;

bool isSame() { //구성이 완전히 같은지 확인하는 함수
    for(int i=0;i<52;i++)
        if(alphabet[i] != alphabetS[i]) return false;
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> g >> s;
    cin >> W >> S;
    
    for(int i=0;i<g;i++) {  //W의 알파벳 구성
        if(W[i] >= 'A' && W[i] <= 'Z') alphabet[W[i]-'A']++;  //대문자일 때
        else alphabet[W[i]-'a' + 26]++;  //소문자일 때
    }
    
    for(int i=0;i<g;i++) {  //S의 처음 알파벳 구성
        if(S[i] >= 'A' && S[i] <= 'Z') alphabetS[S[i]-'A']++;
        else alphabetS[S[i]-'a'+26]++;
    }

    if(isSame()) cnt++;   //처음구성 한번 체크

    for(int i=g;i<s;i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') alphabetS[S[i]-'A']++;
        else alphabetS[S[i]-'a'+26]++;
       // cout << alphabetS[i] << "is plued, " << alphabetS[i-g]
        if(S[i-g] >= 'A' && S[i-g] <= 'Z') alphabetS[S[i-g]-'A']--;
        else alphabetS[S[i-g]-'a'+26]--;

        if(isSame()) cnt++;
    }

    cout << cnt;

    return 0;
}

/*
예전에 풀다가 실패한 문제다. 다시 시도해보자.
|g|는 최대 3,000, |S|는 최대 3,000,000이다. O(S*g)는 절대 안된다.
O(S+g)만에 풀어야 한다. 어떻게 하면 풀 수 있을까...
가능한 모든 순열을 kmp를 사용해 O(S+g)만에 탐색한다.. O(g!(S+g)) 미친짓이다. -> 시간초과

라빈 카프를 시도해봤지만, 라빈 카프도 문자열의 순서가 맞아야 하는 것을 늦게나마 깨달았다.

그냥 아스키값을 빼고 더하는 것은 틀린 해법이다(ex. ad = bc) -> 틀렸습니다.

나만의 해쉬를 만들어 특정 수를 더하고 곱해 확인해 보았다 -> 틀렸습니다.

내가 할 수 있는 모든 방법을 동원해봤지만, 쏟은 시간만 5시간이라 질문글을 올리기로 했다.
대답 -> 나올 수 있는 문자의 종류가 적으니까 각 문자의 개수를 세면 됩니다.

!?.... 문제를 너무 어렵게 생각했었나... 이건 반성할 필요가 있다...
문자열은 대소문자 알파벳으로 이루어져 있으므로, 26+26 = 52가지이다.
52 크기의 배열을 만들어 개수를 세주도록 하겠다. -> 드디어 AC..
*/