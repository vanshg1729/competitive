#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fr first 
#define sc second
struct edge
{
	int a ,b,cost;
};

const ll INF = INT_MIN;
const int maxn = pow(10,3) + 10;
ll dis[maxn] = {};
int n,m,c;

bool solve(vector<edge> e){

	memset(dis,-1,sizeof(dis));
	dis[0] = 0;
	int x = -1;

	for(int i = 1; i <= n; i++){
		x = -1;

		for(auto u : e){

			if(dis[u.a] == -1) continue;
			if(dis[u.b] > dis[u.a] + (ll)u.cost or dis[u.b] == -1){
				dis[u.b] = max(INF,dis[u.a] + (ll)u.cost);
				x = u.b;
			}
		}
	}

	if(x == -1) return false;
	return true;
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>c;

	while(c--){

		cin>>n>>m;

		vector<edge> e = {};
		for(int i = 1; i <= m; i++){
			int a,b,cost; 
			cin>>a>>b>>cost;

			e.push_back({a,b,cost});
		}

		bool b = solve(e);
		if(b) cout<<"possible"<<"\n";
		else cout<<"not possible"<<"\n";
	}
	
}
