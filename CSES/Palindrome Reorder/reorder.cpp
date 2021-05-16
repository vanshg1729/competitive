// https://cses.fi/problemset/task/1755/
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	int arr[40] = {};
	cin >> s;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		arr[s[i] - 'A']++;
	}

	int cn_odd = 0;
	int j = -1;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2) {
			cn_odd++;
			j = i;
		}
	}

	if (cn_odd > 1) {
		cout << "NO SOLUTION";
		return 0;
	}

	char letter = 'A' + j;
	if (j != -1) {
		arr[j]--;
		s[n/2] = letter;

	}
	int k = 0;

	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) continue;

		letter = 'A' + i;
		while (arr[i] > 0) {
			arr[i] -= 2;
			s[k] = s[n - k - 1] = letter;
			k++;
		}
	}

	cout << s;
}
