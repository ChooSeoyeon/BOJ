/*
�Ѽ��� ���� (x,y)�� �ִ�. 
���簢���� �� ���� ��ǥ�࿡ �����ϰ�,
���� �Ʒ� �������� (0,0), 
������ �� �������� (w,h)�� �ִ�.
���簢���� ������� ���� �Ÿ��� �ּҰ��� ���ϴ� ���α׷�

1 �� w, h �� 1,000
1 �� x �� w-1
1 �� y �� h-1
x, y, w, h�� ����
*/

#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min({ w - x, x, h - y, y });
}