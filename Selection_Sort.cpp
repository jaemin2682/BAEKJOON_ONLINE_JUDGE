//�������� : ���ĵ��� ���� ������ �߿��� ���� ���� ���� ã�Ƽ�
//���� ���� �����Ϳ� ��ȯ�� ������ ���
#include <iostream>
using namespace std;
int main() {
	int arr[5] = { 5,3,4,1,2 };
	int min, loc;

	for (int i = 0; i < 5; i++) {
		min = arr[i];
		loc = i;
		for (int j = i+1; j < 5; j++) {
			if (arr[j] < min) {
				min = arr[j];
				loc = j;
			}
		}
		swap(arr[i], arr[loc]);
	}
	for (int i = 0; i < 5; i++) {
		cout << arr[i];
	}
}