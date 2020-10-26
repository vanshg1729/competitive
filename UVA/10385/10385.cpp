#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 30 ;
int n ;   
double run , cyc , t ;
double speed[maxn][2] = {} ; 

double diff(double r)
{
    double time = r/run + (t-r)/cyc ; 
    double mint = r/speed[1][0] + (t-r)/speed[1][1] ;

    for(int i = 2 ; i<n ;i++)
    {
        double ti = r/speed[i][0] + (t-r)/speed[i][1] ;
        mint = min(mint,ti) ;
    } 
    
    return 3600*(mint-time);
}

double ter()
{
    double l = 0 , r = t ;

    while( r-l>=1e-6 )
    {
        double m1 = l + (r-l)/3 ;
        double m2 = r - (r-l)/3 ;
        
        double f1 = diff(m1) ;
        double f2 = diff(m2) ;

        if(f1<f2) l = m1 ;
        else r = m2 ;
    }
    
    double ans = diff(r);
    if(ans>=0)
    {
        cout<<"The cheater can win by "<<fixed<<setprecision(0) ;
        cout<<ans<<" seconds with r = "<<fixed<<setprecision(2) ;
        cout<<r<<"km and k = "<<t-r<<"km."<<"\n" ;
    }
    else
    {
        cout<<"The cheater cannot win."<<"\n" ;
    }

    return 0 ;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);    
    
    while(cin>>t)
    {
        cin>>n ; 

        for(int i = 1 ;i<n ;i++) cin>>speed[i][0]>>speed[i][1] ;

        cin>>run>>cyc ;
        
        ter() ;
    }    
}   
