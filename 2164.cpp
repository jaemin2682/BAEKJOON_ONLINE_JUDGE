#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) q.push(i);

    while(q.size() != 1) {
        q.pop();
        int tem = q.front();
        q.pop();
        q.push(tem);
    }
    cout << q.front();

    return 0;
}