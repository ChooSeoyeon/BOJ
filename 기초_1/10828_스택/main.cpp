#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
	T* stack; //스택 원소를 위한 배열
	int top; //톱 원소의 위치(초기값=-1)
	int capacity; //스택 배열의 크기
public:
	Stack(int stackCapacity = 10);	//처음 크기 stack capacity 공백 스택 생성
	bool empty() const; //스택 원소 수가 0이면 true(1), 아니면 false(0) 반환 (스택이 비어있으면 1, 아니면 0을 출력)
	T Top() const; //스택의 톱 원소를 반환 (스택의 가장 위에 있는 정수를 출력. 만약 스택에 들어있는 정수가 없으면 -1 출력)
	void push(const T& x); //스택의 톱에 x를 삽입 (정수 x를 스택에 넣음)
	T pop(); //스택의 톱 원소를 삭제 (스택에서 가장 위에 있는 정수를 빼고 그 수를 출력, 만약 스택에 들어있는 정수가 없으면 -1 출력)
	T size() const; // (스택에 들어있는 정수의 개수를 출력)
	void ChangeSize1D(T*& a, int oldsize, int newsize);
};

template<class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity) {
	if (capacity < 1)throw "Stack capacity must be >0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::empty() const {
	return top == -1; //스택이 비어있으면 true 즉 1이 반환됨. 아니면 false 즉 0이 반환됨.
}

template<class T>
T Stack<T>::size() const {
	return top + 1;
}
template <class T>
T Stack<T>::Top() const {
	if (empty()) return -1;
	return stack[top];
}

template <class T>
void Stack<T>::push(const T& x) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

template <class T>
T Stack<T>::pop() {
	if (empty()) return -1;
	T temp = stack[top];
	stack[top--].~T();
	return temp;
}

template <class T>
void Stack<T>::ChangeSize1D(T*& a, int oldsize, int newsize) {
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
	Stack<int> s;
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