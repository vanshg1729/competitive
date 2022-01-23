// https://www.codechef.com/IARCSJUD/problems/SORTROWS
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
vector<int> v[maxn] = {};
vector<int> order = {};

bool comp(int a, int b) {

	int size_a = v[a].size(), size_b = v[b].size();
	int i = 0, j = 0;
	while (i < size_a and j < size_b) {
		if (v[a][i] == v[b][j]) {
			i++; j++;
		}
		else break;
	}

	if (j == size_b) return false;
	if (i == size_a) return true;
	return v[a][i] < v[b][j];
}

int main(){

	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n; cin >> n;

	for(int i = 1; i <= n; i++) {
		order.push_back(i);
		int a; cin >> a;

		while (a != -1) {
			v[i].push_back(a);
			cin >> a;
		}
	}

	sort(order.begin(), order.end(), comp);

	for(int i = 0; i < order.size(); i++) {
		int j = order[i];
		for(auto u : v[j]) cout << u << " ";
		cout << "\n";
	}
}
