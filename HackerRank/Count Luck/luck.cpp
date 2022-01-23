#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 110 ;
pair< int ,int > start = {0,0} ;
pair<int,int> e = {0,0} ;

int dfs(int i, int j, int d , int a[maxn][maxn], bool seen[maxn][maxn], int dis[maxn][maxn])
{
    if(seen[i][j] or !a[i][j]) return 0;
    
    dis[i][j] = d ;
    seen[i][j] = true ; 

    int nei = a[i+1][j] + a[i-1][j] + a[i][j+1] + a[i][j-1];
    
    pair<int,int> p = {i,j};

    if(nei > 1 and p == start) d++;
    else if(nei > 2) d++ ;

    dfs(i+1,j,d ,a , seen , dis) ; 
    dfs(i-1, j ,d, a , seen , dis) ;
    dfs(i,j+1, d , a , seen , dis) ;
    dfs(i,j-1,d , a , seen, dis ) ;

    return 0 ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int t ; cin>>t;

    while(t--)
    {
        int n , m, k; cin>>n>>m;
        
        int a[maxn][maxn] = {};
        int dis[maxn][maxn] = {};
        bool seen[maxn][maxn] = {} ;

        for(int i = 1 ; i<= n ; i ++ )
        {
            for( int j = 1 ; j <= m ; j++)
            {
                char c ; cin>>c ;

                a[i][j] = 1 ;

                if(c == 'X') a[i][j] = 0;

                if(c == 'M')
                {
                    start = {i,j} ;
                }

                if(c == '*')
                {
                    e = {i,j};
                }
            }
        }
        
        cin>>k;

        dfs(start.fr, start.sc, 0 ,a , seen , dis);

        if(dis[e.fr][e.sc] == k) 
        {
            cout<<"Impressed"<<"\n";
        }
        else
        {
            cout<<"Oops!"<<"\n";
        }
    }
}
