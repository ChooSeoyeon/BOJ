#include<iostream>
#include<stack>
using namespace std;

/*
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷�
���: push X, pop(���� ���� ���� ���� ���, ������ -1 ���), size(���� ����), 
empty(��������� 1 ���, �ƴϸ� 0 ���), top(���� ���� ���� ���, ������ -1 ���)

[�Է�]
����� �� (1<=N<=10000)
���
���
...

[����] ver2. ���۸� ����
*/
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num; // ����� ��

	string inst; // ���
	int x; // push ��ɾ� �ڿ� ���� ���� X
	stack<int> s; // ������ �����ϴ� ����

	for (int i = 0; i < num; i++) {
		cin >> inst;
		if (inst == "push") { // push X
			cin >> x;
			s.push(x); // X�� ���ÿ� ����
		} 
		else if (inst == "pop") {
			if (!s.empty()) { // ������ ������� �ʴٸ�
				cout << s.top() << "\n";
				s.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (inst == "size") {
			cout << s.size() << "\n";
		}
		else if (inst == "empty") {
			cout << s.empty() << "\n";
		}
		else if (inst == "top") {
			if (!s.empty()) { // ������ ������� �ʴٸ�
				cout << s.top() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
}