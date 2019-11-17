#include <iostream>

using namespace std;

int main() {
    int A[10], B[10], Ascore=0, Bscore=0;
    for(int i=0;i<10;i++) cin >> A[i];
    for(int i=0;i<10;i++) cin >> B[i];
    for(int i=0;i<10;i++) {
        if(A[i] > B[i]) Ascore++;
        else if(A[i] < B[i]) Bscore++;
    }
    if(Ascore > Bscore) cout << "A";
    else if(Ascore < Bscore) cout << "B";
    else cout << "D";

    return 0;
}