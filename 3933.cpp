#include <iostream>
#include <math.h>

using namespace std;

int main() {
    while(1) {
        int n;
        cin >> n;
        if(n==0) break;

        int num = (int)sqrt(n), cnt=0;
        for(int i=1;i<=num;i++) {
            if(i*i == n) {
                cnt++;
                continue;
            }
            else if(i*i > n) break;

            for(int j=i;j<=num;j++) {
                if(j*j + i*i == n) {
                    cnt++;
                    break;
                }
                else if(j*j + i*i > n) break;

                for(int k=j;k<=num;k++) {
                    if(k*k + j*j + i*i == n) {
                        cnt++;
                        break;
                    }
                    else if(k*k + j*j + i*i > n) break;

                    for(int l=k;l<=num;l++) {
                        if(l*l + k*k + j*j + i*i == n) {
                            cnt++;
                            break;
                        }
                        else if(l*l + k*k + j*j + i*i > n) break;
                    }
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
/*
규칙이 보이지 않는다... 4중 FOR문으로 우선 풀어보자 => AC(???)
*/