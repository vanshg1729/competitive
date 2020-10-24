#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = 60010 ; 
pair<double,double> a[maxn] = {} ; 
int n = 0 ;

bool check( double t)
{
    double l = a[1].fr-a[1].sc*t , r = a[1].fr + a[1].sc*t ;  
    for(int i = 1 ;i<=n ;i++)
    {
        l = max(l,a[i].fr - a[i].sc*t) ; 
        r = min(r , a[i].fr + a[i].sc*t) ;  
    }
    
    return l<=r ; 
}

double bin()
{
    double l = 0 , r  = 0 ;

    for(int i = 1 ; i<=n ; i++) r = max(r,a[i].fr) ;

    while(abs(r-l)>pow(10,-6))
    {
        double m = (r+l)/2 ;
        
        //cout<<l<<" "<<r<<endl ;
        if(!check(m)) l = m ; 
        else r = m ; 
    }

    return r ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);    
    
    cin>>n ;
    
    for(int i = 1 ;i<=n ;i++) cin>>a[i].fr ; 

    for(int i = 1;i<=n ;i++) cin>>a[i].sc ; 
    
    printf("%.9f\n",bin()) ; 
    
}
