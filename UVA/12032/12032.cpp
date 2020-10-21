#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = pow(10,5)+10 ; 
int a[maxn] = {} ; 

int check(int h,int n)
{
    for(int i = 0 ;i<n ;i++)
    {
        if(h< a[i+1] -a[i]) return 0 ; 
        else if(h == a[i+1]-a[i]) h-- ; 
    }

    return 1 ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    int t ; cin>>t ; 
    int x = t ; 

    while(t--)
    {
        int n ; cin>>n ; 
        int m = 0 ; 

        for(int i = 1 ;i<=n ;i++)
        {
            cin>>a[i] ; 
            m = max(a[i] - a[i-1],m) ; 
        }

        if(check(m,n)) cout<<"Case "<<x-t<<": "<<m<<"\n" ;
        else cout<<"Case "<<x-t<<": "<<m+1<<"\n";
    }
}
