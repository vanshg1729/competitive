// https://codeforces.com/gym/102644/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll Mod = 1e9 + 7;

struct matrix {
	ll mat[2][2] = {};

	matrix() {}
	matrix(ll b[2][2]) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				mat[i][j] = b[i][j];
			}
		}
	}

	matrix operator*(matrix& other) {
		matrix result;
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < 2; k++) {
				for (int j = 0; j < 2; j++) {
					result.mat[i][k] += mat[i][j]*other.mat[j][k];
					result.mat[i][k] %= Mod;
				}
			}
		}
		return result;
	}
};

ostream& operator<<(ostream& stream, matrix& b) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			stream << b.mat[i][j] << " ";
		}
		stream << "\n";
	}
	return stream;
}

matrix power(matrix a, ll n) {
	matrix product;
	for (int i = 0; i < 2; i++) product.mat[i][i] = 1;
	while (n > 0) {
		if (n % 2) {
			product = product * a;
		}
		a = a * a;
		n /= 2;
	}

	return product;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll n; cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	ll mul[2][2] = {{0, 1}, {1, 1}};
	matrix a(mul);
	matrix fib = power(a, n);
	cout << fib.mat[0][1];	
}
