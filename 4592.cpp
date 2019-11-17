#include <iostream>
#include <vector>

using namespace std;

int main()
{
    while (1) {
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> arr;
        int prev=0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if(prev != num) arr.push_back(num);
            prev = num;
        }
        for(int i=0;i<arr.size();i++) cout << arr[i] << " ";
        cout << "$" << endl;
    }
    return 0;
}