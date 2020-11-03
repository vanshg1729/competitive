#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 2*pow(10,5) +10 ;
int p[maxn] = {} , r[maxn] = {} , deg[maxn] = {} ; 
int T , n , m ; 

int get(int a)
{
    return p[a] = (p[a]==a ? a : get(p[a])) ; 
}

int uni(int a , int b)
{
    a = get(a) ; 
    b = get(b) ; 
    if(a == b) return 0 ; 

    if(r[a] == r[b]) r[a]++ ; 

    if(r[a]>r[b])
    {
        p[b] = a ; 
    }
    else
    {
        p[a] = b ; 
    }

    return 1 ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>T ; 

    while(T--)
    {
        cin>>n>>m ;
        int size = n ;
        
        int ans[n+10] = {} ;  
        vector<int> v[n+10] = {} ; 
        vector<pair<int,int> > edge[n+10] = {} ; 

        for(int i = 1 ; i<=n ; i++)
        {
            p[i] = i ; 
            r[i] = 0 ; 
            deg[i] = 0 ; 
        }

        for(int i = 1 ; i<=m ; i++)
        { 
            int a, b ; cin>>a>>b ; 
            deg[a]++ ; deg[b]++ ; 
            v[a].push_back(b) ; 
        }

        for(int i = 1 ; i<=n ;i++)
        {
            for(int j = 0 ; j<v[i].size() ; j++)
            {
                int d = min(deg[i],deg[v[i][j]]) ; 
                edge[d].push_back({i,v[i][j]}) ; 
            }
        }


        for(int i = n ; i>=1 ; i--)
        {
            for(auto u : edge[i])
            {
                if(uni(u.fr,u.sc)) size-- ; 
            }

            ans[i-1] = size-1 ; 
        }

        for(int i = 0 ; i<n ; i++) cout<<ans[i]<<" " ;

        cout<<"\n" ; 
    }

}   
