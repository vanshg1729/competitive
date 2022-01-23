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
    int n,m ; cin>>n>>m ;
     
     char a[n+10][m+10] = {} ;

     for(int i = 1 ; i<= n ; i ++)
     {
        for(int j = 1 ; j<=m; j++)
        {
            cin>>a[i][j];
        }
     }

     bool cycle = 0 ;

     pair<int ,int > par[n+10][m+10] = {} ;
     
     bool seen[n+10][m+10] = {};
     int f = 4 ;

     pair<int ,int > b[f] = { {1,0} , {-1,0}, {0,1}, {0,-1} } ;

     for(int i = 1; i<= n; i++)
     {
        for(int j = 1; j<=m;j++)
        {
            if(seen[i][j]) continue ;

            queue< pair<int ,int > > q ; 
            seen[i][j] = true ; 
            q.push({i,j});
            par[i][j] = {0,0} ;

            while(!q.empty())
            {
                int x = q.front().fr , y = q.front().sc ;
                q.pop();

                for(auto u : b)
                {
                    int x1 = x+ u.fr , y1 = y + u.sc ; 

                    if(a[x1][y1]!= a[x][y]) continue ;

                    if(seen[x1][y1])
                    {
                        if(par[x1][y1]!=par[x][y] and make_pair(x1,y1)!=par[x][y])
                        {
                            cycle = true ;
                        }

                        continue ;
                    }

                    seen[x1][y1] = true ; 
                    par[x1][y1] = {x,y};
                    q.push({x1,y1});
                }
            }
        }
     }

     if(cycle) cout<<"Yes";
     else cout<<"No";
}
