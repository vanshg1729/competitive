#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 3*pow(10,5)+10 ; 
int a[maxn] = {} ;
bool seen[maxn] = {} ;
vector<pair<int,int> > ans = {} ;


bool comp(int b, int c)
{
     return a[b]<a[c] ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int n ; cin>>n ;

    int team[n+10][4] = {} ;
    vector<int> done = {} , left = {} ;

    for(int i = 1 ;i<=3*n;i++)
    {
        int c ; cin>>c ;
        a[c] = i ;
    }

    for(int i = 1 ;i<=n ;i++)
    {
        vector<int> v ; 
        for(int j = 1 ;j<=3 ;j++)
        {
            int b ; cin>>b ; 
            v.push_back(b) ;
        }
        sort(v.begin(),v.end(),comp) ;

        for(int j = 0 ;j<3 ;j++) team[i][j+1] = v[j] ;
    }

    int k ,m ; cin>>k ;
    bool bo = true ;

    for(int i = 1 ;i<=n ;i++)
    {
        for(int j = 1 ;j<=3 ;j++)
        {
            if(team[i][j]!=k)
            {
                seen[team[i][j]] = true ;
                done.push_back(team[i][j]) ;
            }
        }

        if(team[i][1]==k)
        {
            bo = false ;
            m = max(team[i][2],team[i][3]) ;
            break ;
        }

    }
    
    if(bo)
    {
        for(int i = 1 ;i<=3*n ;i++)
        {
            if(i!=k) cout<<i<<" " ;
        }
        return 0 ;
    }

    sort(done.begin(),done.end()) ;

    for(int i = 0 ;i<done.size() ;i++)
    {
        if(done[i] == m) 
        {
            m = i ; break ;
        }
    }
    
    for(int i = m+1 ;i<done.size() ;i++) left.push_back(done[i]) ;

    for(int i = 1 ;i<=3*n ;i++)
    {
        if(!seen[i] and i!=k) left.push_back(i) ;
    }

    sort(left.begin(),left.end()) ;

    for(int i = 0 ;i<=m ;i++) cout<<done[i]<<" " ;
    for(auto u : left) cout<<u<<" " ;
}
