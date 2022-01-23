#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

vector<int> v = {} ;
int ans = 1 ; 

int unsort(int l , int r,int k )
{
    if(ans == k or r-l == 1) return 0 ; 

    int mid = (l+r)/2 ; 
    
    ans+=2 ;
    swap(v[mid-1],v[mid]) ; 
    unsort(l,mid,k) ; unsort(mid,r,k) ; 
    return 0 ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int n , k ; cin>>n>>k ;

    for(int i = 1 ; i<=n ;i++) v.push_back(i) ;
    
    if(!k)
    {
        for(auto u : v) cout<<u<<" " ; 

        return 0 ; 
    }
    
    unsort(0,n,k) ;
    if(ans!=k) cout<<-1; 
    else for(auto u:v) cout<<u<<" " ;  
}
