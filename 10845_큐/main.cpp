#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

class Queue
{
private:
	int* queue; //ť ���Ҹ� ���� �迭
	int front; //ù��° ����(�ʱⰪ=0)
	int rear; //������ ����(�ʱⰪ=0)
	int capacity; //���� Ȯ���� ť �迭�� ũ��
public:
	Queue(int queueCapacity = 10);	//ó�� ũ�� stack capacity ���� ���� ����
	void ChangeSize1D(int*& a, int oldsize, int newsize);
	bool empty() const; //ť�� ��������� 1(true), �ƴϸ� 0(false)�� ���
	int size() const; // ť�� ����ִ� ������ ������ ���
	int Front() const; //ť�� ���� �տ� �ִ� ������ ���. ���� ť�� ����ִ� ������ ������ -1 ���
	int back() const; //ť�� ���� �ڿ� �ִ� ������ ���. ���� ť�� ����ִ� ������ ������ -1���
	void push(const int& x); //���� x�� ť�� ����
	int pop(); //ť���� ���� ���� �ִ� ������ ���� �� ���� ���, ���� ť�� ����ִ� ������ ������ -1 ���
};

Queue::Queue(int queueCapacity) :capacity(queueCapacity) {
	if (capacity < 1)throw "Queue capacity must be >0";
	queue = new int[capacity];
	front = rear = 0;
}

void Queue::ChangeSize1D(int*& a, int oldsize, int newsize) {
	if (newsize < 0) throw"New length must be >=0";
	int* temp = new int[newsize];
	int number = min(oldsize, newsize);
	copy(a, a + number + 1, temp);
	delete[]a;
	a = temp;
}

inline bool Queue::empty() const {
	return front==rear; //������ ��������� true �� 1�� ��ȯ��. �ƴϸ� false �� 0�� ��ȯ��.
}

int Queue::size() const {
	return rear-front; //���� queue[0][1][2][3]���� push�Ǿ� �ִٸ� rear=4, front=0�̴�. ���� 4-0���� ��ٷ� size�̴�.
}

int Queue::Front() const {
	if (empty()) return -1;
	return queue[front];
}

int Queue::back() const {
	if (empty()) return -1;
	return queue[rear-1]; //���� queue[3]�� push�Ѱ� �������̸� rear=4�̴�. ���� rear-1�� �����ؾ���
}

void Queue::push(const int& x) {
	if (rear == capacity) { //���� ���� �ڸ��� ������ �ڸ��� �����ڸ��� ��ü ũ�� 2�� (���� rear+1���� rear�� ��������)
		ChangeSize1D(queue, capacity, 2 * capacity);
		capacity *= 2;
	}
	queue[rear++] = x;
}

int Queue::pop() {
	if (empty()) return -1;
	int temp = queue[front++];
	return temp;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test;
	cin >> test;

	string user;
	int x;
	Queue q;
	for (int i = 0; i < test; i++)
	{
		cin >> user;
		if (user == "push") {
			cin >> x;
			q.push(x);
		}
		else if (user == "pop") {
			cout << q.pop() << "\n";
		}
		else if (user == "size") {
			cout << q.size() << "\n";
		}
		else if (user == "empty") {
			cout << q.empty() << "\n";
		}
		else if (user == "front") {
			cout << q.Front() << "\n";
		}
		else if (user == "back") {
			cout << q.back() << "\n";
		}
	}
}