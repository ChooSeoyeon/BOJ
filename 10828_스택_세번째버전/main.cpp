#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

class Stack
{
private:
	int* stack; //스택 원소를 위한 배열
	int top; //톱 원소의 위치(초기값=-1)
	int capacity; //스택 배열의 크기
public:
	Stack(int stackCapacity = 10);	//처음 크기 stack capacity 공백 스택 생성
	bool empty() const; //스택 원소 수가 0이면 true(1), 아니면 false(0) 반환 (스택이 비어있으면 1, 아니면 0을 출력)
	int Top() const; //스택의 톱 원소를 반환 (스택의 가장 위에 있는 정수를 출력. 만약 스택에 들어있는 정수가 없으면 -1 출력)
	void push(const int& x); //스택의 톱에 x를 삽입 (정수 x를 스택에 넣음)
	int pop(); //스택의 톱 원소를 삭제 (스택에서 가장 위에 있는 정수를 빼고 그 수를 출력, 만약 스택에 들어있는 정수가 없으면 -1 출력)
	int size() const; // (스택에 들어있는 정수의 개수를 출력)
	void ChangeSize1D(int*& a, int oldsize, int newsize);
};

Stack::Stack(int stackCapacity) :capacity(stackCapacity) {
	if (capacity < 1)throw "Stack capacity must be >0";
	stack = new int[capacity];
	top = -1;
}

inline bool Stack::empty() const {
	return top == -1; //스택이 비어있으면 true 즉 1이 반환됨. 아니면 false 즉 0이 반환됨.
}

int Stack::size() const {
	return top + 1;
}

int Stack::Top() const {
	if (empty()) return -1;
	return stack[top];
}

void Stack::push(const int& x) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

int Stack::pop() {
	if (empty()) return -1;
	int temp = stack[top];
	stack[top--];
	return temp;
}

void Stack::ChangeSize1D(int*& a, int oldsize, int newsize) {
	if (newsize < 0) throw"New length must be >=0";
	int* temp = new int[newsize];
	int number = min(oldsize, newsize);
	copy(a, a + number + 1, temp);
	delete[]a;
	a = temp;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test;
	cin >> test;

	string user;
	int x;
	Stack s;
	for (int i = 0; i < test; i++)
	{
		cin >> user;
		if (user == "push") {
			cin >> x;
			s.push(x);
		}
		else if (user == "pop") {
			cout << s.pop() << "\n";
		}
		else if (user == "size") {
			cout << s.size() << "\n";
		}
		else if (user == "empty") {
			cout << s.empty() << "\n";
		}
		else if (user == "top") {
			cout << s.Top() << "\n";
		}
	}
}