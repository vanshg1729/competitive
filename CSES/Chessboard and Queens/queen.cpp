// https://cses.fi/problemset/result/2161341/
#include <bits/stdc++.h>
using namespace std;

int arr[10][10] = {};
bool col[10] = {}, diag1[20] = {}, diag2[20] = {};	
int cnt;

void solve (int i) {
	if (i == 8) {
		cnt++;
		return;
	}

	for (int j = 0; j < 8; j++) {
		if (arr[i][j] or col[j] or diag1[i + j] or diag2[i + 7 - j]) continue;
		col[j] = 1, diag1[i + j] = 1, diag2[i + 7 - j] = 1;
		solve(i + 1);
		col[j] = 0, diag1[i + j] = 0, diag2[i + 7 - j] = 0;		
	}

	return;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c; cin >> c;
			if (c == '*') arr[i][j] = 1;
		}
	}

	solve(0);
	cout << cnt;
}
