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

    int a[n+10][m+10] = {} ;
    
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=m; j++)
        {
            char c ; cin>>c; 

            a[i][j] = 1 ; 

            if(c == 'X')
            {
                a[i][j] = 0 ; 
            }
        }
    }

    pair<int ,int > st , en ;
    cin>>st.fr>>st.sc>>en.fr>>en.sc ; 
    
    int x = en.fr ,y = en.sc ; 
    int nei = a[x+1][y] + a[x-1][y] + a[x][y+1] + a[x][y-1] ; 
    vector<pair<int,int> > mo = { {1,0},{-1,0},{0,1},{0,-1} } ;

    bool seen[n+10][m+10] = {} ;
    
    seen[st.fr][st.sc] = true ; 
    stack< pair<int,int > > s ; 
    
    s.push({st.fr,st.sc}) ; 

    while(!s.empty())
    {
        int x = s.top().fr , y = s.top().sc ; 
        s.pop();

        for(auto u : mo)
        {
            int x1 = x + u.fr , y1 = y+ u.sc ; 

            if(seen[x1][y1] or !a[x1][y1])
            {
                seen[x1][y1] = true ; 
                continue ;
            }
            
            seen[x1][y1] = true ;
            s.push({x1,y1}) ;  
        }
    }
    
    bool d = false ; 
    for(auto u : mo)
    {
        int x = en.fr + u.fr , y = en.sc + u.sc ; 

        if(st == make_pair(x,y) ) d = true ;
    }

    if(seen[en.fr][en.sc] and nei >1)
    {
        cout<<"YES" ;
    }
    else if(d and nei == 1)
    {
        cout<<"YES";
    }
    else if(st == en)
    {
        if(nei<1) cout<<"NO";
        else cout<<"YES";
    }
    else if(seen[en.fr][en.sc] and !a[en.fr][en.sc])
    {
        cout<<"YES";
    }
    else 
    {
        cout<<"NO";
    }
    
}
