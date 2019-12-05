#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n, sum;
map<int, string> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    m.insert({1, "one"}), m.insert({2, "two"}), m.insert({3, "three"}), m.insert({4, "four"})
    , m.insert({5, "five"}), m.insert({6, "six"}), m.insert({7, "seven"}), m.insert({8, "eight"}), m.insert({9, "nine"})
    , m.insert({10, "ten"}), m.insert({11, "eleven"}), m.insert({12, "twelve"}), m.insert({13, "thirteen"}), m.insert({14, "fourteen"})
    , m.insert({15, "fifteen"}), m.insert({16, "sixteen"}), m.insert({17, "seventeen"}), m.insert({18, "eighteen"}),
    m.insert({19, "nineteen"}), m.insert({20, "twenty"}), m.insert({30, "thirty"}), m.insert({40, "forty"})
    , m.insert({50, "fifty"}), m.insert({60, "sixty"}), m.insert({70, "seventy"}), m.insert({80, "eighty"}), m.insert({90, "ninety"})
    , m.insert({100, "hundred"});
    
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]=="$") continue;
        else sum += v[i].size();
    }
    for(int i=sum+1;i<1000;i++) {
        int size=0;
        string tem;
        if(i <= 19) {       //19 이하일 경우는 그대로
            size = m.find(i)->second.size();
            tem = m.find(i)->second;
        }
        else if(i<100) {    //100 이하일 경우
            if(i%10 == 0) { 
                size = m.find(i)->second.size();  //1의자리수가 0이면 그대로
                tem = m.find(i)->second;
            }
            else {  //아니면 10의자리수 + 1의자리수
                size = m.find(i/10*10)->second.size();
                size += m.find(i%10)->second.size();
                tem = m.find(i/10*10)->second;
                tem += m.find(i%10)->second;
            }
        }
        else if(i<1000) {
            size = m.find(i/100)->second.size(); //100의자리 숫자
            size += m.find(100)->second.size();  //100 
            tem = m.find(i/100)->second;
            tem += m.find(100)->second;
            if(i - i/100*100 <= 19) {
                size += m.find(i - i/100*100)->second.size();
                tem += m.find(i - i/100*100)->second;
            }
            else {
                if((i-i%10)%100 != 0) {
                    size += m.find((i-i%10)%100)->second.size();// 10의 자리
                    tem += m.find((i-i%10)%100)->second;
                }
                if(i%10 != 0) {
                    size += m.find(i%10)->second.size();  //1의 자리
                    tem += m.find(i%10)->second;
                }
            }
        }

        if(sum + size == i) {
            int v_size =v.size();
            for(int k=0;k<v_size;k++) {
                if(v[k] == "$") cout << tem << " ";
                else cout << v[k] << " ";
            }
            break;
        }
    }

    return 0;
}
/*
map을 선언하고, 1~10, 11~19, 20,30,..90, 100을 저장한다.
$를 제외한 모든 문자들의 합의 다음 숫자를 시작으로, 숫자를 늘려가며
문자 수 합 + $의 문자 수 합 = $의 숫자를 만족할 때까지 반복한다.
11111111112222222222333333333344444444445555555555
66666666667777777777888888888899999999990000000000

..정말 풀기 힘든 문제였다. -> AC
*/