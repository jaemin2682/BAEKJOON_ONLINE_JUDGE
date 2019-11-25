#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> problem(n);
    for(int i=0;i<n;i++) cin >> problem[i];
    int rem=0, score=0;
    for(int i=0;i<n;i++) {
        if(problem[i]==1) {
            score += 1 + rem;
            rem++;
        }
        else rem=0;
    }
    cout << score;
    
    return 0;
}
/*
간단한 계산문제이다.
*/