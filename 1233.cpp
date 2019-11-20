#include <iostream>
#include <algorithm>

using namespace std;

int sum[100];

int main() {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    for(int i=1;i<=s1;i++) {    //빈도 계산
        for(int j=1;j<=s2;j++) {
            for(int k=1;k<=s3;k++) {
                sum[i+j+k]++;
            }
        }
    }
    int MaxSum = 0, res;
    for(int i=1;i<=80;i++) MaxSum = max(MaxSum, sum[i]);    //최대값 도출
    for(int i=1;i<=80;i++)      //중복시, 가장 작은값 출력
        if(sum[i] == MaxSum) {
            cout << i;
            break;
        }

    return 0;
}

/*
세 주사위를 던져, 가장 높은 빈도로 나오는 세 주사위의 합.
모든 경우의 세 주사위의 합을 구해, 그 빈도를 배열에 나타내보자.
대신에, 최대 20 * 20 * 40 = 1600번의 연산을 해야한다.


*/