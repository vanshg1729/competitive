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
    
    int t ; cin>>t ; 

    while(t--)
    {
        ll p , idx ; cin>>p>>idx ; 

        ll num = 0 ;
        ll ans = 0 ;

        for(int i = 0 ;i<p ;i++)
        {
            ll po = pow(2,p-i-1) ;

            if( idx>=po+num )
            {
                ans+=pow(2,i) ;
                num+=po ;
            }
        }

        cout<<ans<<"\n" ;
    }
}
