#include <iostream>

using namespace std;

int main() {
	int n, m, k, cnt=-1;	//�� : ��1, ��2
	cin >> n >> m >> k;	//n:����, m:����, k:���Ͻ�
	int num = m;

	for (int i = 0; i <= num; i++) { 
		cnt++;
		if (n < 2 || m < 1) break;
		n -= 2;
		m -= 1;
		if (n + m - k < 0) break;
	}
	cout << cnt;
}

