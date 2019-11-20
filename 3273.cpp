#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, cnt=0;
    scanf("%d",&n);
    vector<int> list(n);
    for(int i=0;i<n;i++) scanf("%d", &list[i]);
    int x;
    cin >> x;
    
    for(int i=0;i<n;i++) {
        if(x > list[i]) {
            int num = x - list[i];
            for(int j=i+1;j<n;j++) {
                if(list[j] == num) {
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d",cnt);

    return 0;
}
/*
각 원소 a의 크기 : 1~100만 -> int 사용
x의 크기 : 1~2백만 -> int 사용
순서대로 왼쪽 + 오른쪽이어야 한다. 왼 > 오로 읽으면 된다.
수열의 크기 n : 1~10만 -> 10*11/2 = 55만번 -> 시간초과

x가 a보다 클 때에만 세도록 함 + printf, scanf 사용 -> 시간초과

같은 수는 없으므로, cnt 증가시킨 다음엔 break,
if문 내의 list[j]+list[i]==x의 매번 연산량을 줄이기 위해 num변수 추가 -> AC

*/