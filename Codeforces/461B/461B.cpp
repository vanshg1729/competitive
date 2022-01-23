#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,5)+10 ; 
ll mod = pow(10,9)+7 ; 
vector<int> a[maxn] = {} ;
ll dp[maxn][2] = {} ;
int col[maxn] = {} , n ;

void dfs(int i , int p)
{
    dp[i][1] = col[i] ;
    dp[i][0] = 1-col[i] ;

    for(auto u : a[i])
    {
        if(u == p) continue ; 

        dfs(u,i) ;

        ll zer = dp[i][0] ;
        ll one = dp[i][1] ;

        dp[i][0] = dp[i][1] = 0 ;

        dp[i][0]+= zer*dp[u][1] ;
        dp[i][1]+= one*dp[u][1] ;

        dp[i][0] += zer*dp[u][0] ;

        dp[i][1] += zer*dp[u][1] + one*dp[u][0] ;

        dp[i][0]%=mod ;
        dp[i][1]%=mod ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);

    cin>>n ; 

    for(int i = 1 ; i<n ; i++)
    {
        int b ; cin>>b ; 
        a[b+1].push_back(i+1) ;
        a[i+1].push_back(b+1) ;
    }
    
    for(int i = 1 ; i<=n ;i++) cin>>col[i] ;

    dfs(1,0) ;
    
    cout<<dp[1][1] ;
}  
