#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 28 ; 
int adj[maxn][maxn] = {} ;
bool cycle = false ; 
bool ans = true ;
int indeg[maxn] = {} ; 
 
int dfs(int i , bool seen[],bool vis[])
{
    vis[i] = true ; 
    for(int j = 0 ; j<26;j++)
    {
        if(!adj[i][j] or seen[j]) continue ; 
        if(vis[j])
        {
            cycle = true ; 
            continue ; 
        }
        dfs(j,seen,vis);
    }
    seen[i] = true ;
    return 0 ; 
}

int check(string u , string v)
{
    int i = 0,j = 0 ;

    while(i<u.size() and j<v.size() and u[i]==v[j])
    {
        i++ ; j++ ;
    }

    if(j == v.size() )
    {
        ans = false ;
        return 0 ; 
    } 
    if(i == u.size()) return 0 ;

    int a = u[i] - 'a' ;
    int b = v[j] - 'a' ;
    if(adj[a][b]) return 0 ; 
    adj[a][b] = 1 ;  
    indeg[b]++ ;
    return 0 ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int n ; cin>>n ; 
    string a ,b ; cin>>a ;
    for(int i = 1 ;i<n ;i++) 
    {
        cin>>b ; 
        check(a,b) ;
        a = b ; 
    }
    
    if(!ans)
    {
        cout<<"Impossible"; 
        return 0 ;
    }

    queue<int> q ; 
    for(int i= 0 ;i<26 ; i++)
    {
        if(!indeg[i]) q.push(i) ; 
        
        bool seen[maxn] = {},vis[maxn] = {} ;
        dfs(i,seen,vis) ;
        if(cycle)
        {
            cout<<"Impossible" ;
            return 0 ; 
        }
    }

    vector<int> top = {} ;
    while(!q.empty())
    {
        int b = q.front() ; q.pop() ;
        top.push_back(b) ; 

        for(int i = 0 ; i<26; i++)
        {
            if(!adj[b][i]) continue ; 
            
            indeg[i]-- ; 
            if(indeg[i] == 0 )
            {
                q.push(i) ;
            }
        }
    }

    for(auto u : top)
    {
        char a = 'a' + u ;
        cout<<a ; 
    }
}
