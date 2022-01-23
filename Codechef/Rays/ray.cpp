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
    
    ll n , m , w ,b ; cin>>n>>m>>w>>b ;

    vector<pair<ll,ll> > v[n+1] = {} ;

    for(int i = 1 ;i<= w ;i++)
    {
        ll x,y ;cin>>x>>y ;
        v[x].push_back({y,1}) ;
    }

    for(int i = 1 ;i<=b ;i++)
    {
        ll x,y ; cin>>x>>y ;
        v[x].push_back({y,0}) ;
    }

    ll ans = 0 ;

    for(int i = 1 ;i<= n ;i++)
    {
        sort(v[i].begin(),v[i].end()) ;

        ll add = (m*(m+1))/2 , z = 0 ;
                
        queue<ll> q ;
        for(int j = 0 ; j<v[i].size() ;j++)
        {
           if(v[i][j].sc == 1)
           {
              add-= m -v[i][j].fr +1 ;

              if(q.empty()) { q.push(v[i][j].fr) ; continue ; }

              if(q.size())
              {
                 add -= (q.front() - z -1)*(m-v[i][j].fr) ;
                 z = q.front() ;
                 q.pop() ;
                 q.push(v[i][j].fr) ; 
              }
           }
           else
           {
              add-= m-v[i][j].fr +1 ;
              
              add -= (v[i][j].fr - z -(ll)1 -(ll)q.size())*(m-v[i][j].fr) ; 
              z = v[i][j].fr ;
              while(!q.empty()) q.pop() ;
           } 
        }
        ans+=add ;
    }

    cout<<ans ;
}
