#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
     
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
     
        ll n , d ; cin>>n>>d ;
     
        vector<pair<ll,ll> > v ; 
        
        v.push_back({0,0}) ; 
        for(int i = 1 ;i<=n ; i++)
        {
        	ll m,s ; cin>>m>>s ;
            
            v.push_back({m,s}) ;
        }
     
        sort(v.begin(),v.end()) ;
     
        ll pre[n+1] = {} ;
     
        for(int i = 1 ;i<=n ; i++)
        {
        	pre[i] = pre[i-1]+v[i].sc ; 
        }
     
        ll ans = 0 ;

        vector<ll> z = {} ;
        for(int i = 0 ; i<=n ;i++) z.push_back(v[i].fr) ;
     
        for(int i = 1 ;i<=n ;i++)
        {
        	int j = upper_bound(z.begin(),z.end(),v[i].fr+d-1) -z.begin() ; j-- ;
     
        	ans = max(ans,pre[j] - pre[i-1]) ;
        }
     
        cout<<ans ;
    }
