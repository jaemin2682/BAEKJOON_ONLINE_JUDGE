#include <iostream>
#include <string>

using namespace std;

string str, bomb, ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> str >> bomb;

    int Ssize = str.size();
	int Bsize = bomb.size();

    for (int i = 0; i < Ssize; i++) {
		ans += str[i];
		if (str[i] == bomb[Bsize - 1]) {
			bool isBomb = true;
			for (int j = 0; j < Bsize; j++) {
				if (ans[ans.size() - 1 - j] != bomb[Bsize - 1 - j]) {
					isBomb = false;
					break;
				}
			}
			if (isBomb) ans.erase(ans.end() - Bsize, ans.end());
		}
	}
	
	if (ans.empty()) cout << "FRULA";
	else cout << ans;

	return 0;
}
/*
while문으로 계속 폭탄유무를 체크해서 지워준다. 탈출 시기는 이전 문자열 크기를 기억해서
이전 크기와 다음 크기가 같으면 폭발물이 없는 것이므로 탈출한다. -> 시간초과

-> 한 번 돌때 모두 처리하자. 어떻게? 폭탄을 지우면 폭탄의 size만큼 idx를 뺀다.(안전하게)
idx가 0보다 작아지면 0으로 처리! - >시간초과

-> 앞에서부터 빼면 계속 문자열이 밀려 처리를 어쩔 수 없이 해줘야 한다. 나의 두 번째 시도처럼.
이 시간조차 아끼려면 문자열의 맨 뒤부터 시작해서 폭탄의 뒷글자로 확인해나간다.
그럼 아직 탐색하지 않은 구역은 문자열이 밀리지 않으니 추가적인 처리 연산이 필요없다! -> 시간초과

-> 슬슬 힘이 빠진다. 위의 코드는 O(N)인데 왜 시간초과가 나는거지..??
공간을 조금 더 활용하고 속도를 조금 더 줄여보아야겠다. 답안을 위한 string을 하나 더 만든다.
이러면 for문 돌 때마다 체크하는 str의 size를 구하는 부분을 없앨 수 있다. -> AC 휴...

*/