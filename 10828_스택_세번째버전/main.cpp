#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

class Stack
{
private:
	int* stack; //���� ���Ҹ� ���� �迭
	int top; //�� ������ ��ġ(�ʱⰪ=-1)
	int capacity; //���� �迭�� ũ��
public:
	Stack(int stackCapacity = 10);	//ó�� ũ�� stack capacity ���� ���� ����
	bool empty() const; //���� ���� ���� 0�̸� true(1), �ƴϸ� false(0) ��ȯ (������ ��������� 1, �ƴϸ� 0�� ���)
	int Top() const; //������ �� ���Ҹ� ��ȯ (������ ���� ���� �ִ� ������ ���. ���� ���ÿ� ����ִ� ������ ������ -1 ���)
	void push(const int& x); //������ �鿡 x�� ���� (���� x�� ���ÿ� ����)
	int pop(); //������ �� ���Ҹ� ���� (���ÿ��� ���� ���� �ִ� ������ ���� �� ���� ���, ���� ���ÿ� ����ִ� ������ ������ -1 ���)
	int size() const; // (���ÿ� ����ִ� ������ ������ ���)
	void ChangeSize1D(int*& a, int oldsize, int newsize);
};

Stack::Stack(int stackCapacity) :capacity(stackCapacity) {
	if (capacity < 1)throw "Stack capacity must be >0";
	stack = new int[capacity];
	top = -1;
}

inline bool Stack::empty() const {
	return top == -1; //������ ��������� true �� 1�� ��ȯ��. �ƴϸ� false �� 0�� ��ȯ��.
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