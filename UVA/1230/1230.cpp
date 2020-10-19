#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

ll expo(ll x, ll pow , ll n)
{ 
    if(pow == 1) return x%n;

    if(pow%2) return (x*expo(x,pow-1,n))%n ; 
    else
    {
        ll y = expo(x,pow/2,n) ; 
        return (y*y)%n ;  
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    int c ; cin>>c ; 

    while(c--)
    {
        ll x , y , n ; cin>>x>>y>>n ; 

        cout<<expo(x,y,n)<<"\n" ; 
    }
}
