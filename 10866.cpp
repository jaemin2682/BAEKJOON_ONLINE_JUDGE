#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> Deque;
    for(int i=0;i<n;i++) {
        string cmd;
        cin >> cmd;
        if(cmd=="push_front") {
            int num;
            cin >> num;
            Deque.insert(Deque.begin(), num);
        }
        else if(cmd == "push_back") {
            int num;
            cin >> num;
            Deque.push_back(num);
        }
        else if(cmd == "pop_front") {
            if(Deque.size()) {
                cout << Deque[0] << endl;
                Deque.erase(Deque.begin());
            }
            else cout << -1 << endl;
        }
        else if(cmd == "pop_back") {
            if(Deque.size()) {
                cout << Deque[Deque.size()-1] << endl;
                Deque.erase(Deque.begin()+Deque.size()-1);
            }
            else cout << -1 << endl;
        }
        else if(cmd=="size") cout << Deque.size() << endl;
        else if(cmd=="empty") {
            if(Deque.size()) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if(cmd=="front") {
            if(Deque.size()) cout <<Deque[0] << endl;
            else cout << -1 << endl;
        }
        else if(cmd=="back") {
            if(Deque.size()) cout << Deque[Deque.size()-1] << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}
/*
덱이라는 자료구조를 구현하는 내용이다. 맨 앞과 뒤에서 pop이 가능해야 하니, vector로 만든다.
*/