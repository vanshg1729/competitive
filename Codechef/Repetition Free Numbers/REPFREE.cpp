// https://www.codechef.com/IARCSJUD/problems/REPFREE
#include <bits/stdc++.h>
using namespace std;
int Max_Num = 987654321;

bool check(int n) {
	int seen[10] = {};
	while (n) {
		int dig = n % 10;
		if (seen[dig] or dig == 0) return 0;
		seen[dig] = 1;
		n /= 10;
	}

	return 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	if (n >= Max_Num) {
		cout << 0;
		return 0;
	}

	for (int i = n + 1; i < Max_Num; i++) {
		if (check(i)) {
			cout << i;
			return 0;
		}
	}
}
