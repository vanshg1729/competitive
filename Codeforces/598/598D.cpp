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

    int n,m,k ; cin>>n>>m>>k;

    int a[n+1][m+1] = {};
    for(int i = 1; i<=n ;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            char c ; cin>>c;
            
            a[i][j] = 1 ;
            if(c == '*') a[i][j] = 0;
        }
    }

    int seen[n+1][m+1] = {} ; 
    vector<int> v; v.push_back(0) ;
    vector<pair<int,int> > mo = { {1,0},{-1,0},{0,1},{0,-1} } ;

    for(int i = 1 ; i<=n;i++)
    {
        for(int j = 1 ; j<= m ; j++)
        {
            if(seen[i][j] or !a[i][j]) continue ; 

            int c = v.size() ; 
            seen[i][j] = c ;

            int pic = 0 ;

            stack<pair<int ,int > > s ; 

            s.push({i,j}) ; 

            while(!s.empty())
            {
                int x = s.top().fr , y = s.top().sc ; 
                s.pop();
                
                for(auto u : mo)
                {
                   int x1 = x + u.fr , y1 = y+ u.sc ;
                   
                   if(!a[x1][y1])
                   {
                      pic++;
                      continue ;  
                   }

                   if(seen[x1][y1]) continue ; 

                   seen[x1][y1] = c;
                   s.push({x1,y1}) ;    
                }

            }

            v.push_back(pic) ;
        }
    }

    for(int z = 1 ;z<=k ; z++)
    {
        int i , j ; cin>>i>>j ;

        cout<<v[seen[i][j]]<<"\n";
    }

}
