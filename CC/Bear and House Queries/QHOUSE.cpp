// https://www.codechef.com/LRNDSA04/problems/QHOUSE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int x, int y) {
	cout << "? " << x << " " << y << endl;
	string res; cin >> res;
	if (res.compare("YES") == 0) return true;
	return false; 
}

int sqaure() {
	int k = 0;

	for (int d = 1000; d >= 1; d /= 2) {
		while (k + d <= 1000 and check(k + d, 0)) k += d;
	}

	return k;
}

int triangle(int y) {
	int k = 0;

	for (int d = 1000; d >= 1; d /= 2) {
		while (k + d <= 1000 and check(k + d, y)) k += d;
	}

	return k;
}

int height() {
	int k = 0;

	for (int d = 1000; d >= 1; d /= 2) {
		while (k + d <= 1000 and check(0, k + d)) k += d;
	}

	return k;
}

int main() {

	long long sq_side = 2*sqaure();

	long long tri_side = 2*triangle(sq_side);

	long long tri_height = height() - sq_side;

	long long area = sq_side * sq_side + (tri_side * tri_height)/2;

	cout << "! " << area << "\n";
}
