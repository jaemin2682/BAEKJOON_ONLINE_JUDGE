#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> friends(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        friends[a]++; friends[b]++;
    }
    for(int i=1;i<=n;i++) printf("%d\n",friends[i]);

    return 0;
}
/*
그냥 세서 출력한다. -> 시간초과(???)
cin, cout -> scanf, printf -> AC
*/