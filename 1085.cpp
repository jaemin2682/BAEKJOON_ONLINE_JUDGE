#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(min(min(w-x, h-y), x), y);

    return 0;
}

/*
좌표가 배열의 순서와 다르기 때문에, 배열의 순서에 맞게 변형해서 풀겠다.
왼쪽아랫점이 0, 0 (출발) : (0, 0)
오른쪽 위 꼭짓접이 w, h : (h, w)
한수의 위치 x, y : (y, x)
...라고 풀려 했지만, 간단하게 w, h는 무조건 x, y보다 높으므로 경계선까지 최솟값은
w-x, h-y 중 작은 값이다. -> 틀렸다.
-> 직사각형인데 축에 맞닿은 지점은 생각을 안했다. 추가하자. x-0, y-0. 즉, x, y도 추가한다.
-> AC
*/