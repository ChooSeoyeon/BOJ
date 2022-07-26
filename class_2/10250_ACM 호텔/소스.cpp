#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int>a(3);
	vector<int>b(3);
	while (1)
	{
		cin >> a[0] >> a[1] >> a[2];
		if (a==b) break;
		sort(a.begin(), a.end());
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}