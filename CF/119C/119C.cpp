#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

struct data{
    ll a , b , c , pos ; 
}; 

bool comp(data x , data y)
{
    return x.c < y.c ;
}

ll dp[60][110][60] = {} ;
pair<ll,ll> p[60][110][60] = {} ;
data sb[60] = {} ;
ll n , m , k ; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k ;

    sb[0].a = sb[0].b = sb[0].c = sb[0].pos = 0 ;
    for(int i = 1 ; i<=m ; i++)
    {
        cin>>sb[i].a>>sb[i].b>>sb[i].c ;
        sb[i].pos = i ;
    }

    sort(sb , sb+ m+1 , comp) ;
    pair<int,int> state = {0, 0} ;

    for(int i = 1 ; i<=m ; i++)
    {
        for(int j = 0 ; j<= sb[i].b - sb[i].a ; j++)
        {
            dp[i][j][1] = sb[i].a + j ;

            for(int z = 2 ; z<= n ;z++)
            {
                dp[i][j][z] = -1 ;

                for(int l = i-1 ; l>=1 ; l--)
                {
                    if(sb[i].c <= sb[l].c) continue ; 

                    for(int t = 0 ; t<=1 ; t++)
                    {
                        ll work = sb[i].a + j;
                        bool yes = (t == 0) ? work%k == 0 : work>=k ;

                        if(!yes) continue ;

                        work = (t == 0) ? work/k : work -k ;

                        if(!(work >= sb[l].a and work <= sb[l].b )) continue ;
                        work -= sb[l].a ;

                        if(dp[l][work][z-1] == -1) continue ; 

                        if(dp[l][work][z-1] + sb[i].a + j > dp[i][j][z] )
                        {
                            dp[i][j][z] = dp[l][work][z-1] + sb[i].a + j ;
                            p[i][j][z] = {l , work} ;
                        }
                    }
                }

            }

            if(dp[i][j][n] > dp[state.fr][state.sc][n])
            {
                state = {i,j} ;
            }
        }
    }

    if(dp[state.fr][state.sc][n] <=0 ) 
    {
        cout<<"NO" ;
        return 0 ;
    }

    stack<pair<ll,ll> > q ;
    cout<<"YES"<<"\n" ;

    while(n)
    {
        ll i = sb[state.fr].pos ;
        ll j = sb[state.fr].a + state.sc ;

        q.push({i,j}) ;
        state = p[state.fr][state.sc][n] ;
        n-- ;
    }

    while(!q.empty())
    {
        cout<<q.top().fr<<" "<<q.top().sc<<"\n" ;
        q.pop() ;
    }
}   
