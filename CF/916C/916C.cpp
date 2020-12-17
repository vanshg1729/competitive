#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define ll long long 

const int maxe = pow(10,9);
const int prime = pow(10,5)+3;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n , m; cin>>n>>m;

	if(n == 2){
		cout<<2<<" "<<2<<"\n";
		cout<<1<<" "<<2<<" "<<2;
		return 0;
	}

	cout<<2<<" "<<prime<<"\n";

	m = m-n+1;
	cout<<1<<" "<<2<<" "<<prime-n+1<<"\n";

	for(int i = 3; i < n; i++){

		cout<<1<<" "<<i<<" "<<1<<"\n";
	}

	cout<<1<<" "<<n<<" "<<2<<"\n";

	for(int i = 2; i <=n; i++){

		for(int j = i+1; j <= n; j++){
			if(!m) return 0;
			m--;
			cout<<i<<" "<<j<<" "<<maxe<<"\n";
		}
	}

}
