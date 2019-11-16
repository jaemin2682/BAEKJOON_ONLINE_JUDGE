#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr(5);
    for(int i=0;i<5;i++) cin >> arr[i];
    int cnt = 0, num = 1;
    while(cnt<3) {
        cnt = 0;
        num++;
        for(int i=0;i<5;i++) {
            if(num%arr[i] == 0) cnt++;
        }
    }
    cout << num;

    return 0;
}