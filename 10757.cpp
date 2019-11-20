#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, ans;
    cin >> a >> b;
    if(b.size() > a.size()) swap(a, b); //a가 더 길게 만들어줌
    bool up =false;
    int Bsize = b.size(), Asize = a.size();
    for(int i=Bsize-1, j=Asize-1;i>=0;i--, j--) {   //작은 수의 사이즈만큼
        int num = a[j]-48 + b[i]-48;
        if(up) { 
            num += 1;
            up = false;
        }
        if(num > 9) {
            up = true;
            num-=10;
        }
        ans.insert(0, to_string(num));
    }

    if(Asize > Bsize) {
        for(int i=Asize-Bsize-1;i>=0;i--){
            int num = a[i]-48;
            if(up) { 
                num += 1;
                up = false;
            }
            if(num > 9) {
                up = true;
                num-=10;
            }
            ans.insert(0, to_string(num));
        }
    }
    if(up) ans.insert(0, "1");
    cout << ans;
    return 0;
}