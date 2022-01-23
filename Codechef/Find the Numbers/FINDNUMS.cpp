// https://www.codechef.com/IARCSJUD/problems/FINDNUMS
#include <bits/stdc++.h>
using namespace std;
int k, s, p;
int a[6] = {1, 1, 1, 1, 1, 1};
bool b = false;
vector<int> factors = {};

void possible(int n) {

	if (b) return;
	if (n == factors.size()) {
		int sum = 0;
		for(int i = 1; i <= k; i++) {
			sum += a[i];
		}

		if (sum == s) {
			b = true;
			for(int i = 1; i <= k; i++) {
				cout << a[i] << " ";
			}
		}
		return;
	}

	for(int i = 1; i <= k; i++) {
		a[i] *= factors[n];
		possible(n + 1);
		a[i] /= factors[n];
	}

	return;
} 


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s >> p >> k;

	int i = 2;

	while (p > 1) {

		while (p % i == 0) {
			factors.push_back(i);
			p /= i;
		}

		i++;
	}

	possible(0);

	if (!b) cout << "NO";
}
