#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

vector<int> v = {} ; 

int mer(int l, int m , int r)
{
    queue<int> q ; 

    int i = l , j = m +1 ; 

    while(i<=m or j<=r)
    {
        if(i>m or (i<=m and j<=r and v[i]>v[j]))
        {
            q.push(v[j]) ; j++ ;
            ans+= (ll)m-i+1 ;
        }
        else
        {
            q.push(v[i]) ; i++ ;
        }
    }

    for(int i = l ; i<= r; i++)
    {
        v[i] = q.front() ; q.pop() ;
    }

    return 0 ;
}


int sort(int l, int r)
{
    if(l==r) return 0 ;
    if(r-l==1)
    {
        if(v[l]>v[r]){ swap(v[l],v[r]) ; ans++ ; } 
        return 0 ;
    } 

    int m = (l+r)/2 ; 
    sort(l,m) ; sort(m+1,r) ;
    
    mer(l,m,r) ;
    return 0 ; 
}


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
        ans = 0 ;
        int n ; cin>>n ; n ;
        for(int i = 0 ;i<n ;i++)
        {
            int a ; cin>>a ; 
            v.push_back(a) ;
        }

        sort(0,n-1) ; 
        cout<<ans<<"\n" ;

        while(v.size()) v.pop_back() ;
    }
}
