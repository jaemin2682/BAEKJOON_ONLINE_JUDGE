#include <iostream>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    for(int i=0;i<q;i++) {
        int a;
        scanf("%d", &a);
        if(a&(a-1)) printf("0\n");
        else printf("1\n");
    }

    return 0;
}

/*
각 수를 2의 거듭제곱으로 나타낼 수 있는지 판단하는 문제
계속 2로 나누다가 1이 되면 맞는거고, 1이 되기 전에 2로 나눠지지 않으면 아닌걸로 작성 -> 시간초과

a가 2^31-1 이하 자연수라 한 수당 30번 언저리의 연산이어서 될 줄 알았는데 q가 10^6까지였다..

-> 비트연산으로 푼다.
a가 2의 거듭제곱일 경우, 100000..꼴이 나오게 된다. a-1은 1111..꼴이다. 
즉, a&(a-1)을 해주면, 2의 거듭제곱의 경우 0이 나오게 된다. -> 시간초과

->..? cin, cout -> scanf, printf.. -> AC...

*/