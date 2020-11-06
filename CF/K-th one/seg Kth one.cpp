// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5)+10 ; 
int t[4*maxn] = {} , a[maxn] = {} ; 
int n ,m ; 

void build(int v , int l , int r )
{
    if(l == r)
    {
        t[v] = a[l] ; 
    }
    else
    {
        int m = (l+r)/2 ; 
        build(2*v, l , m) ; 
        build(2*v+1,m+1,r) ; 

        t[v] = t[2*v] + t[2*v+1] ; 
    }
}

void update(int v , int tl , int tr , int pos )
{
    if(tl == tr)
    { 
        t[v] = a[pos]  ; 
    }
    else
    {
        int tm = (tl + tr)/2 ; 

        if(pos<=tm) update(2*v,tl,tm , pos ) ; 
        else update(2*v+1,tm+1,tr , pos ) ; 

        t[v] = t[2*v] + t[2*v+1] ; 
    }
}

int find(int v , int tl , int tr , int k)
{
    if(tl == tr) return tl ; 

    int tm = (tl + tr)/2 ; 

    if(k <= t[2*v] ) return find(2*v, tl , tm , k) ; 
    else return find(2*v+1, tm+1, tr , k - t[2*v]) ; 

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>n>>m ; 

    for(int i = 0 ; i<n ; i++) cin>>a[i] ; 

    build(1,0,n-1) ; 
    
    while(m--)
    {
        int type , b ; cin>>type>>b ; 

        if(type == 1)
        {
            a[b]^=1 ; 
            update(1,0,n-1,b) ; 
        }
        else
        {
            cout<<find(1,0,n-1,b+1)<<"\n" ; 
        }
    }

}   
