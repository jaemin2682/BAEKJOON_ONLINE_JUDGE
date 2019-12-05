#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
string sound;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    cin.ignore();
    for(int i=0;i<t;i++) {
        getline(cin, sound);
        vector<string> store;
        int size = sound.size();

        string tem;
        for(int j=0;j<size;j++) {   //울음소리들을 하나씩 저장
            if(sound[j] == ' ') {
                store.push_back(tem);
                tem = "";
            }
            else tem+=sound[j];
        }
        store.push_back(tem);

        while(1) {
            string others;
            getline(cin, others);
            if(others == "what does the fox say?") break;

            string temp;
            int idx=0, others_size = others.size();
            for(int j=0;j<others_size;j++) {    //마지막 단어를 뽑는 과정
                if(others[j] == ' ') idx++;
                if(idx==2) {
                    idx = j+1;
                    break;
                }
            }
            for(int j=idx;j<others_size;j++)
                temp += others[j];
            
            for(int j=0;j<store.size();j++) {
                if(temp == store[j]) {
                    store.erase(store.begin() + j);
                    j--;
                }
            }
            
        }
        int store_size = store.size();
        for(int j=0;j<store_size;j++) cout << store[j] << " ";
    
    }

    return 0;
}
/*
what does the fox say? 라는 입력 때문에 울음소리와 각각의 동물소리를 전부 다 line으로
입력받아 나누어주어야 해서 귀찮은 문제였다.
그거 외에는 어려운 점은 없었다.
*/