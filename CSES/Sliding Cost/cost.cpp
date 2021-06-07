// https://cses.fi/problemset/task/1077/
#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long

const int maxn = 2e5 + 10;
ll arr[maxn] = {};
int n, k;
ll top_sum = 0, bot_sum = 0;
set<pair<int, int> > bot, top;
pair<int,int> med = {-1, -1};

void fix() {
	int siz = top.size() + bot.size();
	if (bot.size() < siz/2) {
		bot.insert(med);
		bot_sum += med.fr;
		med = *top.begin();
		top.erase(med);
		top_sum -= med.fr;
	}
	else if (bot.size() > siz/2) {
		top.insert(med);
		top_sum += med.fr;
		med = *--bot.end();
		bot.erase(med);
		bot_sum -= med.fr;
	}
}

void add(pair<int, int> x) {
	if (med.fr == -1) {
		med = x; return;
	}
	if (x < med) {
		bot.insert(x);
		bot_sum += x.fr;
	}
	else {
		top.insert(x);
		top_sum += x.fr;
	}
	fix();

}

void del(pair<int, int> x) {
	if (x == med) {
		med = *top.begin();
		top.erase(med);
		top_sum -= med.fr;
	}
	else if (x < med) {
		bot.erase(x);
		bot_sum -= x.fr;
	}
	else {
		top.erase(x);
		top_sum -= x.fr;
	}
	fix();
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (k == 1) {
		for (int i = 0; i < n; i++) cout << 0 << " ";
		return 0;
	}

	for (int i = 0; i < k - 1; i++) add({arr[i], i});

	for (int i = k - 1; i < n; i++) {
		add({arr[i], i});
		cout << med.fr*bot.size() - bot_sum + top_sum - med.fr*top.size() << " ";
		del({arr[i - k + 1], i - k + 1});
	}
}


