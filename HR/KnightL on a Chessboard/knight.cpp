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
    
    int n ; cin>>n;

    for(int a = 1; a<n;a++)
    {
        for(int b = 1; b<n;b++)
        {
           bool seen[n+10][n+10] = {};

           int dis[n+10][n+10] = {};
           
           vector<pair<int,int> > m = { {a,b},{-a,-b},{a,-b},{-a,b},{b,a},{-b,-a},{-b,a},{b,-a} };
           queue<pair <int,int> > q ; 
           seen[0][0] = {};
           q.push({0,0}) ;

           while(!q.empty())
           {
              int x = q.front().fr , y = q.front().sc;
              q.pop();

              for(auto u : m)
              {
                 int x1 = x + u.fr , y1 = y + u.sc ;

                 if(x1 < 0 or x1>=n or y1<0 or y1 >=n ) continue ;

                 if(seen[x1][y1]) continue ; 

                 seen[x1][y1] = true ; 

                 dis[x1][y1] = dis[x][y] +1;
                 
                 q.push({x1,y1}) ;
              }
           }

           if(seen[n-1][n-1]) cout<<dis[n-1][n-1]<<" ";
           else cout<<-1<<" ";
        }

        cout<<endl;
    }
}
