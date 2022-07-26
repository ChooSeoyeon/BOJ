#include<iostream>
#include<stack>
using namespace std;

/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램
명령: push X, pop(가장 위의 정수 빼고 출력, 없으면 -1 출력), size(정수 개수), 
empty(비어있으면 1 출력, 아니면 0 출력), top(가장 위의 정수 출력, 없으면 -1 출력)

[입력]
명령의 수 (1<=N<=10000)
명령
명령
...

[버전] ver2. 구글링 참고
*/
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num; // 명령의 수

	string inst; // 명령
	int x; // push 명령어 뒤에 붙을 숫자 X
	stack<int> s; // 정수를 저장하는 스택

	for (int i = 0; i < num; i++) {
		cin >> inst;
		if (inst == "push") { // push X
			cin >> x;
			s.push(x); // X를 스택에 넣음
		} 
		else if (inst == "pop") {
			if (!s.empty()) { // 스택이 비어있지 않다면
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
			if (!s.empty()) { // 스택이 비어있지 않다면
				cout << s.top() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
}