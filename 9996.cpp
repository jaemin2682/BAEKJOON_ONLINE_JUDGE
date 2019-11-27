#include <iostream>
#include <string>
using namespace std;

int n, starIdx;
string pattern, filename;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> pattern;

    string prev, post;  //별의 이전, 이후 문자열
    int psize = pattern.size();
    for(int i=0;i<psize;i++) {  //이전 문자열 구함
        if(pattern[i] == '*') {
            starIdx = i;
            break;
        }
        prev += pattern[i];
    }

    for(int i=starIdx+1;i<psize;i++) post += pattern[i];    //이후 문자열 구함
    int postsize = post.size();

    for(int i=0;i<n;i++) {
        cin >> filename;
        int fsize = filename.size();
        bool isRight = true;

        for(int j=0;j<starIdx;j++)  //이전 문자열 검증
            if(filename[j] != prev[j]) {
                isRight = false;
                break;
            }

        if(isRight) {       //이후 문자열 검증
            for(int j=fsize-1, k=postsize-1;j>=fsize-postsize;j--, k--)
                if(filename[j] != post[k]) {
                    isRight = false;
                    break;
                }
        }

        if(starIdx - 1 >= fsize - postsize) isRight = false;

        if(isRight) cout << "DA";
        else cout << "NE";
        cout << endl;
    }
    return 0;
}

/*
별표는 문자열의 시작과 끝이 아니다. 즉, 별표를 기준으로 왼쪽의 알파벳들과 오른쪽의 알파벳들을
뽑아서, 파일 이름들의 왼쪽과 오른쪽을 검사하면 될 것 같다. -> 틀렸습니다

-> abcd*cdef ,  abcdef의 경우 나는 DA로 뜨는데, 문자열을 중복 검증한다. 이게 문제같다.
왼쪽 문자열의 오른쪽 끝의 인덱스가 오른쪽 문자열의 왼쪽 끝 인덱스보다 크거나 같으면 DA로
조정해야겠다. -> AC

*/