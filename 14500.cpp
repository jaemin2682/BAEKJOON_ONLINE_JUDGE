#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> line_hor = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
vector<pair<int, int>> line_ver = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
vector<pair<int, int>> square ={{0, 0}, {1, 0}, {0, 1}, {1, 1}};
vector<vector<pair<int, int>>> giuk_ver = {{{0, 0}, {1, 0}, {2, 0}, {2, 1}}, {{0, 0}, {0,1},{1,1},{2,1}},{{0,0},{0,1},{1,0},{2,0}},{{2,0},{2,1},{1,1},{0,1}}};
vector<vector<pair<int, int>>> giuk_hor ={{{0,0},{1,0},{0,1},{0,2}},{{1,0},{1,1},{1,2},{0,2}},{{0,0},{0,1},{0,2},{1,2}},{{0,0},{1,0},{1,1},{1,2}}};
vector<vector<pair<int, int>>> riul_ver={{{0,0},{1,0},{1,1},{2,1}},{{0,1},{1,1},{1,0},{2,0}}};
vector<vector<pair<int, int>>> riul_hor={{{0,0},{0,1},{1,1},{1,2}},{{1,0},{1,1},{0,1},{0,2}}};
vector<vector<pair<int, int>>> fxxx_hor={{{1,0},{1,1},{1,2},{0,1}},{{0,0},{0,1},{0,2},{1,1}}};
vector<vector<pair<int, int>>> fxxx_ver={{{1,0},{0,1},{1,1},{2,1}},{{0,0},{1,0},{2,0},{1,1}}};
int n, m;
int paper[501][501];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> paper[i][j];

    int max_val = 0;
    for(int i=1;i<=n;i++) { //LINE도형(HORIZON이 더 넓은) 4/1
        for(int j=1;j<=m-3;j++) {
            int val = 0;
            for(int k=0;k<4;k++)
                val += paper[i+line_hor[k].first][j+line_hor[k].second];
            max_val = max(max_val, val);
        }
    }
    for(int i=1;i<=n-3;i++) { //LINE도형(VERTICAL이 더 넓은) 1/4
        for(int j=1;j<=m;j++) {
            int val = 0;
            for(int k=0;k<4;k++)
                val += paper[i+line_ver[k].first][j+line_ver[k].second];
            max_val = max(max_val, val);
        }
    }
    for(int i=1;i<=n-1;i++) { //SQUARE도형 2/2
        for(int j=1;j<=m-1;j++) {
            int val = 0;
            for(int k=0;k<4;k++)
                val += paper[i+square[k].first][j+square[k].second];
            max_val = max(max_val, val);
        }
    }
    for(int i=1;i<=n-2;i++) { // 3/2 (VERTICAL이 더 넓은)
        for(int j=1;j<=m-1;j++) {
            for(int k=0;k<giuk_ver.size();k++) { //'ㄱ' 도형
                int val = 0;
                for(int l=0;l<4;l++) val += paper[i+giuk_ver[k][l].first][j+giuk_ver[k][l].second];
                max_val = max(max_val, val);
            }
            for(int k=0;k<riul_ver.size();k++) { //'ㄹ' 도형
                int val = 0;
                for(int l=0;l<4;l++) val += paper[i+riul_ver[k][l].first][j+riul_ver[k][l].second];
                max_val = max(max_val, val);
            }
            for(int k=0;k<fxxx_ver.size();k++) { //'ㅗ' 도형
                int val = 0;
                for(int l=0;l<4;l++) val += paper[i+fxxx_ver[k][l].first][j+fxxx_ver[k][l].second];
                max_val = max(max_val, val);
            }
        }
    }
    for(int i=1;i<=n-1;i++) { // (HORIZON이 더 넓은) 2/3
        for(int j=1;j<=m-2;j++) {   
            for(int k=0;k<giuk_hor.size();k++) {    //'ㄱ'
                int val = 0;
                for(int l=0;l<4;l++) val += paper[i+giuk_hor[k][l].first][j+giuk_hor[k][l].second];
                max_val = max(max_val, val);
            }
            for(int k=0;k<riul_hor.size();k++) {    //'ㄹ'
                int val = 0;
                for(int l=0;l<4;l++) val += paper[i+riul_hor[k][l].first][j+riul_hor[k][l].second];
                max_val = max(max_val, val);
            }
            for(int k=0;k<fxxx_hor.size();k++) {    //'ㅗ'
                int val = 0;
                for(int l=0;l<4;l++) val += paper[i+fxxx_hor[k][l].first][j+fxxx_hor[k][l].second];
                max_val = max(max_val, val);
            }
        }
    }
    
    cout << max_val;
    
    
    return 0;
}

/*
주어진 테트로미노들 중 하나를 사용하여, 숫자가 새겨진 모눈종이에 올려놓아 모눈의 합이
최대가 되는 수를 구하는 문제이다. 도형을 회전, 대칭 시킬 수도 있다.
ㅡ도형은 ㅡ와 ㅣ, ㄱ도형은 회전과 대칭을 이용해 8가지 도형, ㄹ자 도형은 4가지,
ㅗ자 도형은 4가지, ㅁ자 도형은 자체로 하나이다.
정말 짜는게 고통스러웠고 이게 맞나 싶기도 했다.
그래도 최대한 연산과 저장을 따로하는 것은 놓치지 않으려 했다. -> AC
*/



