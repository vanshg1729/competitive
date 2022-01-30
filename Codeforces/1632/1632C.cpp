#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
const int maxn = 2e5 + 10;

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--){
		int a, b; cin >> a >> b;

		int ans = b - a;
		int count = -1;
		for (int i = a; i < b; i++){
			count++;
			ans = min(ans, count + (i | b) - b + 1);
			int k = i;
			int power = 0;
			while (k){
				k /= 2;
				power++;
			}

			//printf("power = %d\n", power);
			int pow = (1 << power) - 1;
			int num = b & pow;
			k = i;
			if (num > k){
				for (int j = power - 1; j >= 0; j--){
					int bita = (k & (1 << j)), bitb = (num & (1 << j));
					if (bitb and !bita) k += (1 << j);
					if (bita and !bitb) break;
				}
			}
				
			int diff = k - num;
			//printf("i = %d, num = %d, pow = %d, diff = %d, count = %d\n",i, num, pow, diff, count); 
			//cout << a << " " << count << " " << diff << endl;
			ans = min(ans, count + diff + 1);
		}

		cout << ans << "\n";
	}

}
