#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int five = n / 5;
	int five_last = n % 5;
	int three;
	int three_last = -1;

	if (three_last != 0) {
		while (five_last <n) {
			three = five_last / 3;
			three_last = five_last % 3;
			if (three_last == 0) break;
			five_last += 5;
			five--;
		}
	}

	if (three_last != 0) {
		three = n / 3;
		three_last = n % 3;
		five = 0;
	}
	
	if (three_last==0)	cout << five + three << "\n";
	else cout << "-1\n";
}