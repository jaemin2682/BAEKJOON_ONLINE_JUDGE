#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;  
    
    for(int i=0;i<n;i++) cout << '*';   //첫째줄
    for(int i=0;i<1+(n-2)*2;i++) cout << ' ';
    for(int i=0;i<n;i++) cout << '*';
    cout << endl;

    for(int i=1;i<=n-1;i++) {   //윗단, 중간단
        for(int j=1;j<=i;j++) cout <<' ';
        cout << '*';
        for(int j=1;j<=n-2;j++) cout << ' ';
        cout << '*';
        if(i!=n-1) {
            for(int j=1;j<(n-1-i)*2;j++) cout << ' ';
            cout << '*';
        }
        for(int j=1;j<=n-2;j++) cout << ' ';
        cout << '*';
        cout << endl;
    }

    for(int i=1;i<=n-2;i++) {   //아랫단
        for(int j=1;j<=n-1-i;j++) cout << ' ';
        cout << '*';
        for(int j=1;j<=n-2;j++) cout << ' ';
        cout << '*';
        for(int j=1;j<=(i*2)-1;j++) cout << ' ';
        cout << '*';
        for(int j=1;j<=n-2;j++) cout << ' ';
        cout << '*';
        cout << endl;
    }


    for(int i=0;i<n;i++) cout << '*';   //마지막줄
    for(int i=0;i<1+(n-2)*2;i++) cout << ' ';
    for(int i=0;i<n;i++) cout << '*';

    return 0;
}
/*
총 열의 개수 : n + (n-1), 첫째 마지막 빼면 n-1 + n-2
첫째줄, 마지막줄 : n개 *, 1 + (n-2)*2개의 공백, n개 *
나머지 : 공백이 1~n-1까지 늘었다가 다시 1로 줄어든다. 
나는 이런 그림 그리는 문제가 싫다.
*/