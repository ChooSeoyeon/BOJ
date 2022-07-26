#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
	T* stack; //���� ���Ҹ� ���� �迭
	int top; //�� ������ ��ġ(�ʱⰪ=-1)
	int capacity; //���� �迭�� ũ��
public:
	Stack(int stackCapacity = 10);	//ó�� ũ�� stack capacity ���� ���� ����
	bool empty() const; //���� ���� ���� 0�̸� true(1), �ƴϸ� false(0) ��ȯ (������ ��������� 1, �ƴϸ� 0�� ���)
	T Top() const; //������ �� ���Ҹ� ��ȯ (������ ���� ���� �ִ� ������ ���. ���� ���ÿ� ����ִ� ������ ������ -1 ���)
	void push(const T& x); //������ �鿡 x�� ���� (���� x�� ���ÿ� ����)
	T pop(); //������ �� ���Ҹ� ���� (���ÿ��� ���� ���� �ִ� ������ ���� �� ���� ���, ���� ���ÿ� ����ִ� ������ ������ -1 ���)
	T size() const; // (���ÿ� ����ִ� ������ ������ ���)
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
	return top == -1; //������ ��������� true �� 1�� ��ȯ��. �ƴϸ� false �� 0�� ��ȯ��.
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