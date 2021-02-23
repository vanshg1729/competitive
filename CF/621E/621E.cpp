// https://codeforces.com/problemset/problem/621/E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;


struct matrix{

	vector<vector<ll>> mat = {};
	int siz = 0;
	matrix() {}
	matrix(int size) {
		siz = size;
		mat = vector<vector<ll>>(size, vector<ll>(size, 0));
	}

	matrix operator*(matrix& other) {
		matrix res(siz);
		for (int i = 0; i < siz; i++) {
			for (int k = 0; k < siz; k++) {
				for (int j = 0; j < siz; j++) {
					res.mat[i][k] += mat[i][j] * other.mat[j][k];
					res.mat[i][k] %= Mod;
				}
			}
		}
		return res;
	}
};

matrix expo_power(matrix& mul, int n, int x) {
	matrix res(x);
	for (int i = 0; i < x; i++) res.mat[i][i] = 1;

	while (n > 0) {
		if (n % 2) {
			res = res * mul;
		}

		mul = mul * mul;
		n /= 2;
	}

	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, b, k, x; cin >> n >> b >> k >> x;

	matrix mul(x);
	int freq[10] = {};
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		freq[a]++;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 1; j < 10; j++) {
			int rem = ((i * 10) + j) % x;
			mul.mat[i][rem] += freq[j];
		}
	}

	matrix res = expo_power(mul, b, x);
	cout << res.mat[0][k];
}
