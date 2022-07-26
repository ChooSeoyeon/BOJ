/*
한수는 지금 (x,y)에 있다. 
직사각형은 각 변이 좌표축에 평행하고,
왼쪽 아래 꼭짓점은 (0,0), 
오른쪽 위 꼭짓점은 (w,h)에 있다.
직사각형의 경계산까지 가는 거리의 최소값을 구하는 프로그램

1 ≤ w, h ≤ 1,000
1 ≤ x ≤ w-1
1 ≤ y ≤ h-1
x, y, w, h는 정수
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