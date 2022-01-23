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
    
    int T ;cin>>T ;

    while(T--)
    {
        int n , k ;cin>>n>>k ; 
        ll start[n+10] = {} ;
        ll end[n+10] = {} ;
        stack<pair<ll,ll> > rem[4] = {} ;
        
        for(int i = 1 ;i<=n ;i++)
        {
            char c ; cin>>c ;
            if(c=='X') rem[i%3].push({i,0}) ;
            if(c=='Z')
            {
                int r = (i+1)%3 ; 
                if(!rem[r].empty()) end[i]+=rem[r].size() ; 
                if(!rem[r].empty()) rem[r].top().sc++ ;
            }
        }

        for(int i = 0 ;i<3 ;i++)
        {
            ll s = 0 ;
            while(!rem[i].empty())
            {
                auto b = rem[i].top() ; rem[i].pop() ;
                s+=b.sc ;
                start[b.fr]+= s ;
            }
        }
        
        ll dp[n+10] = {} ;
        ll ans = 0 ; 
        for(int i = 1 ;i<=k ;i++) ans+=start[i] ;

        dp[k] = ans ;
        for(int i = k+1 ;i<=n ; i++)
        {
            dp[i] = dp[i-1] + start[i] - end[i-k] ;
            ans = min(dp[i],ans) ;
        }

        cout<<ans<<"\n" ;
    }
}
