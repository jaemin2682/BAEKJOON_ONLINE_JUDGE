#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        bool alphacheck[26];
        memset(alphacheck, false, sizeof(alphacheck));
        string str;
        getline(cin, str);

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
            {
                alphacheck[str[j] - 'A'] = true;
            }
            else if (str[j] >= 'a' && str[j] <= 'z')
            {
                alphacheck[str[j] - 'a'] = true;
            }
        }
        bool check = true;
        for (int j = 0; j < 26; j++)
        {
            if (!alphacheck[j])
            {
                check = false;
                break;
            }
        }
        if (check)
            cout << "pangram" << endl;
        else
        {
            cout << "missing ";
            for (int j = 0; j < 26; j++)
            {
                if (!alphacheck[j]) {
                    char al = 'a' + j;
                    cout << al;
                }
            }
            cout << endl;
        }
    }
    return 0;
}