#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

class Queue
{
private:
	int* queue; //큐 원소를 위한 배열
	int front; //첫번째 원소(초기값=0)
	int rear; //마지막 원소(초기값=0)
	int capacity; //현재 확보된 큐 배열의 크기
public:
	Queue(int queueCapacity = 10);	//처음 크기 stack capacity 공백 스택 생성
	void ChangeSize1D(int*& a, int oldsize, int newsize);
	bool empty() const; //큐가 비어있으면 1(true), 아니면 0(false)을 출력
	int size() const; // 큐에 들어있는 정수의 개수를 출력
	int Front() const; //큐의 가장 앞에 있는 정수를 출력. 만약 큐에 들어있는 정수가 없으면 -1 출력
	int back() const; //큐의 가장 뒤에 있는 정수를 출력. 만약 큐에 들어있는 정수가 없으면 -1출력
	void push(const int& x); //정수 x를 큐에 넣음
	int pop(); //큐에서 가장 위에 있는 정수를 빼고 그 수를 출력, 만약 큐에 들어있는 정수가 없으면 -1 출력
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
	return front==rear; //스택이 비어있으면 true 즉 1이 반환됨. 아니면 false 즉 0이 반환됨.
}

int Queue::size() const {
	return rear-front; //현재 queue[0][1][2][3]까지 push되어 있다면 rear=4, front=0이다. 따라서 4-0값이 곧바로 size이다.
}

int Queue::Front() const {
	if (empty()) return -1;
	return queue[front];
}

int Queue::back() const {
	if (empty()) return -1;
	return queue[rear-1]; //현재 queue[3]에 push한게 마지막이면 rear=4이다. 따라서 rear-1로 접근해야함
}

void Queue::push(const int& x) {
	if (rear == capacity) { //현재 넣을 자리가 마지막 자리의 다음자리면 전체 크기 2배 (원래 rear+1에서 rear로 수정했음)
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