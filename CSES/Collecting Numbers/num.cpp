// https://cses.fi/problemset/task/2216/
#include <bits/stdc++.h>
using namespace std;


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int arr[n + 10] = {};
	for (int i = 1; i <= n; i++) {
		int b; cin >> b;
		arr[b] = i;
	}

	int rounds = 1;

	for (int i = 2; i <= n; i++) {
		if (arr[i] < arr[i - 1]) rounds++;
	}

	cout << rounds;
}
