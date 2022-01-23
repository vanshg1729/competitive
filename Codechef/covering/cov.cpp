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
    
    int n ; cin>>n ; 
    pair<int,int> a[n] = {} ; 
    for(int i = 0 ;i<n ;i++)
    {
        cin>>a[i].fr>>a[i].sc ;
    }

    sort(a,a+n) ; 

    pair<int,int> curr = {a[0].fr,a[0].sc} ; 

    int ans = 1 ;

    for(int i = 1 ;i<n ;i++)
    {
        if(a[i].fr > curr.sc) 
        {
            ans++ ; 
            curr = a[i] ; 
        }
        else
        {
            curr.fr = a[i].fr ; 
            curr.sc = min(a[i].sc,curr.sc) ; 
        }
    }

    cout<<ans ; 
}
