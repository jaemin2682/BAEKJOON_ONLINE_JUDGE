#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum=0, factor=2, idx=1;
    while(1) {
        sum += factor;
        factor*=2;
        if(sum >= n) break;
        idx++;
    }   //idx자릿수 수이다.
    int order = n - (sum - factor/2)-1; // index크기의 order번째
//    cout << "order : " << order << endl;

    string str;// 1 1
    while(order > 0) { // 7 > 3 1
        int num = order%2;
        order/=2;
        str.insert(0, to_string(num));
    }
    int size = str.size();
    for(int i=0;i<idx-size;i++) str.insert(0, "0");
 //   cout << "str : " << str << endl;
    
    for(int i=0;i<idx;i++) {
        if(str[i] == '0') cout << 4;
        else if(str[i]=='1')cout << 7;
    }
    return 0;
}

/*
한자릿수 = 2가지, 두자릿수는 4가지, 세자릿수는 8가지...의 경우의 수를 가지므로, 자릿수를 구한다.

*/