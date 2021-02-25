// https://dmoj.ca/problem/apio07p2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int l, r;
    ll len;
};

bool comp(edge& lhs, edge& rhs) {
	if (lhs.len == rhs.len) return false;
	return lhs.len > rhs.len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    int arr[n + 10] = {};
    int left[n + 10] = {}, right[n + 10] = {};
    ll dis_l[n + 10] = {}, dis_r[n + 10] = {};
    int seen[n + 10] = {};

    priority_queue<edge, vector<edge>, decltype(&comp) > q(&comp);
    int count = 0;

    for (int i = 1; i <= n; i++) {
    	cin >> arr[i];
    	left[i] = i - 1;
    	right[i] = i + 1;
    	if (i > 1) dis_l[i] = arr[i] - arr[i - 1];
    	if (i > 1) dis_r[i - 1] = arr[i] - arr[i - 1];
    }

    for (int i = 2; i <= n; i++) {
    	q.push({i - 1, i, arr[i] - arr[i - 1]});
    }

    ll sum = 0;
    while (count < k) {
    	auto b = q.top(); q.pop();

    	if (seen[b.l] or seen[b.r]) continue;
    	seen[b.l] = seen[b.r] = 1;
    	count++;
    	sum += b.len;

    	//cout << b.l << " " << b.r << " " << b.len << endl;
    	if (b.l == 1 or b.r == n) continue;
    	int lt = left[b.l], rt = right[b.r];

    	if (seen[lt] or seen[rt]) continue;

    	right[lt] = rt; left[rt] = lt;
    	ll dis = dis_l[b.l] + dis_r[b.r] - b.len;
    	dis_r[lt] = dis_l[rt] = dis;

    	q.push({lt, rt, dis});
    }

    cout << sum;
}
