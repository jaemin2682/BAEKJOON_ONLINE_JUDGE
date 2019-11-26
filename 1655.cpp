#include <iostream>
#include <queue>

using namespace std;

int n, num;
priority_queue<int> Maxheap;
priority_queue<int, vector<int>, greater<int>> Minheap;

int main() {
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%d", &num);
        if(Maxheap.size() > Minheap.size()) Minheap.push(num);
        else Maxheap.push(num);

        if(!Maxheap.empty() && !Minheap.empty() && Maxheap.top() > Minheap.top()) {
            int Maxtop = Maxheap.top(), Mintop = Minheap.top();
            Maxheap.pop(); Minheap.pop();           //swap
            Maxheap.push(Mintop); Minheap.push(Maxtop);
        }
        printf("%d\n", Maxheap.top());
    }
    
    return 0;
}
/*
최대힙과 최소힙을 이용한다.
최대힙과 최소힙의 크기는 항상 같거나 최대힙이 1 더 크다.
최소 힙의 top이 최대 힙의 top보다 항상 커야 한다. 작으면 두 힙의 top을 swap한다.
그럼 항상 최대힙의 top이 중간값이다.
*/