#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        string message, rule;
        cin.ignore();
        getline(cin, message);
        cin >> rule;

        for(int j=0;j<message.size();j++) {
            if(message[j] <= 'Z' && message[j] >= 'A')
                message[j] = rule[message[j]-'A'];
        }

        cout << message << endl;
    }

    return 0;
}