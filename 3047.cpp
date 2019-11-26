#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    vector<int> arr(3);
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    sort(arr.begin(), arr.end());

    string str;
    cin >> str;
    vector<int> order;
    for(char a : str) order.push_back(a - 'A');
    for(int i=0;i<3;i++) printf("%d ", arr[order[i]]);

    return 0;
}
/*
받은 숫자를 정렬하여 원래 A, B, C 순서를 만들고 입력받은 String의 순서를
다른 vector에 저장해 넣는다. 그 저장해 놓은 순서에 따라 정렬한 vector의 값을 출력한다.
*/