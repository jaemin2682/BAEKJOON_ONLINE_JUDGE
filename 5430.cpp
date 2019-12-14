#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int T;

int main() {
    cin >> T;
    for(int test_case=0;test_case<T;test_case++) {
        string p, arrStr;
        int n;
        deque<int> arr;
        cin >> p >> n >> arrStr;
        
        int arrStrSize = arrStr.size(), pSize = p.size();
        string temp;
        for(int i=0;i<arrStrSize;i++) { //정수 배열 만드는 과정 O(arrStr.size)
            if(arrStr[i] == '[') { }
            else if(arrStr[i] == ',' || arrStr[i] == ']') {
                if(!temp.empty()) {
                    arr.push_back(stoi(temp));
                    temp = "";
                }
            }
            else temp += arrStr[i];
        }
        
        bool isError = false;   //에러인지 체크
        bool isLeft = true; //왼쪽부터 볼지 오른쪽부터 볼지(빠르게 뒤집기 위해)
        for(int i=0;i<pSize;i++) {
            if(p[i]=='R') {
                if(isLeft) {
                    isLeft = false;
                }
                else isLeft = true;
            }
            else {
                if(arr.empty()) {
                    isError = true;
                    break;
                }

                if(isLeft) arr.pop_front();
                else arr.pop_back();
            }
        }
        if(!isLeft) reverse(arr.begin(), arr.end());

        int arrSize = arr.size();
        if(isError) cout << "error" << '\n';
        else {
            cout << '[';
            for(int a=0;a<arrSize;a++) {
                if(a == arrSize-1) cout << arr[a];
                else cout << arr[a] << ',';
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}
/*
새로운 언어 AC : 정수 배열 연산 언어
R : 배열에 있는 숫자의 순서를 뒤집는다.
D : 첫 숫자를 버린다.(비어있는데 사용 시 에러)

-> 시간초과.

정수 배열 만드는 데에 O(arrStr.size), 함수 실행하는 데에 O(P.size*arr.size)
p는 10만까지, 배열 안의 수도 10만까지이기 때문에 무조건 시간초과가 난다.
함수 실행에서 쓴 revere함수가 아닌 더 빠른 방식으로 뒤집을 수 있게끔 구현해야겠다.
isLeft라는 bool 변수를 두어 직접 뒤집는 대신 삭제할 때 처음/마지막 삭제의 기준이 되게 했다.
-> 시간초과.

erase연산도 오바였던 것 같다. 덱을 사용해 pop_front, pop_back을 이용하자.


*/