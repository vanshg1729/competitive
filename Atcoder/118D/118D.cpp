#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,4)+10 ;
string dp[maxn] = {};
int seen[maxn] = {} ;

vector<int> v = {} ;

int num[10] = {0,2,5,5,4,5,6,3,7,6} ;
string ch[10] = {"0","1","2","3","4","5","6","7","8","9"} ;

int find(int i)
{
    if(i < 0 ) return 0 ;
    if(seen[i] == 1) return 1 ;
    else if(seen[i]) return 0 ;

    seen[i] = 2 ;

    for(auto u : v)
    {
        int j = i - num[u] ;

        if(j == 0 and dp[i].size() == 1)
        {
            seen[i] = 1 ;
            dp[i] = max(dp[i] , ch[u]) ;
        }

        if(!find(j)) continue ;

        if(dp[j].size() + 1 == dp[i].size() )
        {
            dp[i] = max(dp[i] , max(dp[j] + ch[u] , ch[u] + dp[j]) ) ;
        }

        if(dp[j].size() +1 > dp[i].size() )
        {
            seen[i] = 1 ; 
            dp[i] = max(dp[j] + ch[u] , ch[u] + dp[j]) ;
        } 
    } 

    if(seen[i] == 1) return 1 ;
    else return 0 ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);
 
    int n , m ; cin>>n>>m ;
    seen[0] = 1 ;

    for(int i = 1 ;i<=m ;i++)
    {
        int a ; cin>>a ;
        v.push_back(a) ;
    }

    find(n) ;
    
    cout<<dp[n] ;
}   
