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

    int n,m,k; cin>>n>>m>>k;
    
    int c = 0; 
    int a[n+10][m+10] = {};

    for(int i = 1; i<=n; i ++)
    {
        for(int j = 1; j<=m; j++)
        {
            char d ; cin>>d;

            if(d == '.')
            {
                a[i][j] = 1;
                c++;
            }

            else continue ; 
        }
    }
    
    bool seen[n+1][m+1] = {};

    for( int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(seen[i][j] or !a[i][j] ) continue ;

            stack< pair<int,int> > s ;

            seen[i][j] = true ;

            s.push({i,j}) ;

            while(!s.empty())
            {
                int x = s.top().fr , y = s.top().sc ;

                s.pop();

                if(c <= k) a[x][y] = 2 ;
                c--;

                if(a[x+1][y] and !seen[x+1][y])
                {
                    s.push({x+1,y}) ;
                    seen[x+1][y] = true ;
                }

                if(a[x-1][y] and !seen[x-1][y])
                {
                    s.push({x-1,y});
                    seen[x-1][y] = true ;
                }

                if(a[x][y+1] and !seen[x][y+1])
                {
                    s.push({x,y+1}) ;
                    seen[x][y+1] = true ; 
                }

                if(a[x][y-1] and !seen[x][y-1])
                {
                    s.push({x,y-1}) ;
                    seen[x][y-1] = true ;
                }
            }
        }
    }

    for( int i = 1; i <= n ; i ++ )
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(a[i][j] == 1) cout<<".";
            else if(a[i][j]== 2) cout<<"X";
            else cout<<"#";
        }

        cout<<"\n" ;
    }
}
