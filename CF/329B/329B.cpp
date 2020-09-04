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
    
    int n,m; cin>>n>>m; 
    int a[n+10][m+10] = {};
    pair<int,int> st,en;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            char c ; cin>>c; 

            if(c == 'E')
            {
                en = {i,j};
            }
            else if(c == 'S')
            {
                st = {i,j};
            }
            else if(c=='T')
            {
                a[i][j] = -1;
            }
            else
            {
                a[i][j] = c - '0';
            }


        }
    }
    
    vector<pair<int,int> > mo = { {1,0},{-1,0},{0,1},{0,-1} } ;

    bool seen[n+10][m+10] = {} , vis[n+10][m+10] = {};
    int dis[n+10][m+10] = {}, len[n+10][m+10] = {} ;

    queue<pair<int,int> > q ; 
    q.push({st.fr,st.sc}); seen[st.fr][st.sc] = true ;
    
    while(!q.empty())
    {
        int x = q.front().fr , y = q.front().sc;
        q.pop() ;

        for(auto u : mo)
        {
            int x1 = x + u.fr , y1 = y+u.sc ;

            if(seen[x1][y1] or a[x1][y1] == -1 ) continue ;
            if(x1 < 1 or x1 > n or y1 <1 or y1 > m) continue ;

            seen[x1][y1] = true ;
            dis[x1][y1] = dis[x][y] +1 ;
            q.push({x1,y1}) ;
        }
    }

    int d = dis[en.fr][en.sc] ;
    int ans = 0 ;
    q.push({en.fr,en.sc}) ; vis[en.fr][en.sc] = true ;
  
    while(!q.empty())
    {
        int x = q.front().fr , y = q.front().sc;
        q.pop() ;

        for(auto u : mo)
        {
            int x1 = x + u.fr , y1 = y+u.sc ;

            if(vis[x1][y1] or a[x1][y1] == -1 ) continue ;
            if(x1 <1 or x1 >n or y1 < 1 or y1 > m) continue ;

            vis[x1][y1] = true ;
            len[x1][y1] = len[x][y] +1 ;
            if(len[x1][y1]<= d)
            {
                ans += a[x1][y1] ;
            }
            q.push({x1,y1}) ;
        }
    }
    
    cout<<ans;
}
