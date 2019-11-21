#include <iostream>
#include <string>

using namespace std;

int main() {
    string n, mem, ans;
    cin >> n;
    mem = n;    //처음 받은 수
    n += "0000";    //shift한 수

    int memsize = mem.size(), nsize = n.size(), nidx=nsize-1;
    bool up = false;
    for(int i=memsize-1 ;i>=0;i--, nidx--) {
        int num;
        if(up) {
            num = mem[i]-48 + n[nidx]-48 + 1;
            up = false;
        }
        else num = mem[i]-48 + n[nidx]-48;

        if(num >= 2) {
            num-=2; up=true;
        }
        
        ans.insert(0, to_string(num));
    }

    while(nidx > -1) {
        int num;
        if(up) {
            num = n[nidx]-48 + 1;
            up = false;
        }
        else num = n[nidx]-48;

        if(num >= 2) {
            num-=2; up=true;
        }
        ans.insert(0, to_string(num));
        nidx--;
    }

    if(up) ans.insert(0, "1");
    cout << ans;

    return 0;
}
/*
입력되는 이진수 N은 최대 1000자리 이진수. long long으로도 부족함. 2진법->10진법->2진법 불가.
17배는 16배+1이기 때문에, 입력받은 이진수를 모두 4칸씩 shift하고, 1배(처음 받은 수)를 더한다.
1111 -> 15, 11110000 -> 240.   240+15 = 15*17 = 255
-> AC
*/