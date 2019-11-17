#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        string str;
        cin >> str;
        char first = str[0], second;
        int size = str.size();
        if(size==1) second = str[0];
        else second = str[1];

        int index=0;
        do {
            cout << str[index];
            index = (index + 2)%size;
        } while(str[index] != first);
        cout << endl;

        index=1;
        if(size == 1) cout << str[0];
        else {
            do {
               cout << str[index];
              index = (index + 2)%size;
            } while(str[index] != second);
        }
        cout << endl;
    }

    return 0;
}