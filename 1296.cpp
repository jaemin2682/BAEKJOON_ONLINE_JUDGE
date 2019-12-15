#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string myname, name;
vector<pair<int, string>> scores;

bool comp(pair<int, string> a, pair<int, string> b) {
    if(a.first < b.first) return false;
    else if(a.first > b.first) return true;
    else {
        if(a.second > b.second) return false;
        else return true;
    } 
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> myname >> n;
    int mynameSize = myname.size(), L=0, O=0, V=0, E=0;
    for(int i=0;i<mynameSize;i++) {
        if(myname[i]=='L') L++;
        else if(myname[i] == 'O') O++;
        else if(myname[i] == 'V') V++;
        else if(myname[i] == 'E') E++;
    }

    for(int i=0;i<n;i++) {
        cin >> name;
        int score = 0, Lsum=L, Osum=O, Vsum=V, Esum=E, nameSize=name.size();
        for(int j=0;j<nameSize;j++) {
            if(name[j]=='L') Lsum++;
            else if(name[j]=='O') Osum++;
            else if(name[j]=='V') Vsum++;
            else if(name[j]=='E') Esum++;
        }
        score = ((Lsum+Osum)*(Lsum+Vsum)*(Lsum+Esum)*(Osum+Vsum)*(Osum+Esum)*(Vsum+Esum)) % 100;
        scores.push_back({score, name});
    }

    sort(scores.begin(), scores.end(), comp);
    //for(pair<int, string> a : scores) cout << a.first << " : " << a.second << endl;
    cout << scores[0].second;

    return 0;
}
/*
vector<pair<int, string>>을 사용하여 점수->이름 순으로 정렬하기 편하게 선언해준다.
각 이름에 맞게 점수를 계산해주면 될 것 같다.
하지만 코딩하다 보니 점수는 높은순, 이름은 사전순이었다.. 비교함수를 정의해주자.
*/