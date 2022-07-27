#include <iostream>
#include <stack>
using namespace std;

/*
[문제]
1~n까지의 수를 오름차순 순서대로 스택에 넣었다가 뽑아서 수열 만듬.
주어진 수열을 위 방법으로 만들수 있는지 없는지(NO) 출력. 
있다면 push(+), pop(-) 순서를 출력.

[입력]
n (1<=n<=100,000)
1~n 사이 중 하나 (중복x)
1~n 사이 중 하나 (중복x)
... (1~n 사이 모두 나올 때까지)

[버전] ver1. 스스로 해결
[시간] 3:30~

[생각] 본인 차례에 들어올 수 있는 후보 생각
본인보다 큰 애가 나오기 전까진 오름차순 가능
본인보다 큰 애가 나온 후엔 내림차순만 가능
4
3 // 3,5,6,7,8 가능
6 // 2,5,6,7,8 가능
8 // 5,7,8 가능
7
5
2
1
*/
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int x; // 주어진 수열 항 하나씩 입력받기 위해 사용하는 변수
	int max = 0;
	stack<int> s;
	stack<char> op;
	for (int i = n; i > 0; i--) {
		s.push(i);
	}
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		
	}
	

}