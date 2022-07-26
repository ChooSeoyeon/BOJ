#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	bool* prime = new bool[n + 1];

	//fill_n(prime, n + 1, true); 바로 아래 for문 대신 써봤더니 12ms 걸림
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= n; i++) { //8ms 걸림
		prime[i] = true;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				prime[j] = 0;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i]) cout << i << "\n";
	}
}