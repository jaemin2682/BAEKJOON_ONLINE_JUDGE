#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPrime(int num) {
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    vector<int> list;
    cin >> n;
    int factor=2;
    while(1) {
        if(n==1) return 0;
        else if(IsPrime(n)) {
            list.push_back(n);
            break;
        }
        else if(n % factor == 0) {
            n /= factor;
            list.push_back(factor);
            if(n==1) break;
        }
        else {
            factor++;
        }
    }
    sort(list.begin(), list.end());
    for(int i=0;i<list.size();i++) cout << list[i] << endl;

    return 0;
}