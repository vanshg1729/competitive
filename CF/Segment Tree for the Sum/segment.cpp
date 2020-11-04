// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5) + 10 ; 
int n , m ; 
ll t[4*maxn] = {} , a[maxn] = {} ; 

void build(int v , int l , int r)
{
    if(l == r)
    {
        t[v] = a[l] ; 
    }
    else
    {
        int m = (l+r)/2 ; 
        build(2*v,l,m) ; 
        build(2*v+1,m+1,r) ; 
        t[v]  = t[2*v] + t[2*v+1] ;  
    }
} 

void update(int v , int l , int r , int pos , ll ne)
{
    if(l == r)
    {
        t[v] = ne ; 
    }
    else
    {
        int m = (l+r)/2 ; 
        if(pos<=m)
        {
            update(2*v,l,m,pos,ne) ; 
        }
        else
        {
            update(2*v+1,m+1,r,pos,ne) ; 
        }

        t[v] = t[2*v]+t[2*v+1] ; 
    }
}

ll sum(int v , int tl , int tr, int l , int r)
{
    if(l > r) return 0 ; 

    if(l == tl and r == tr)
    {
        return t[v] ; 
    }

    int m = (tl+tr)/2 ; 

    return sum(2*v,tl,m,l,min(r,m)) + sum(2*v+1,m+1,tr,max(l,m+1),r) ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ; 
    //freopen("output.txt","w",stdout);
    cin>>n>>m ; 

    for(int i = 0 ; i<n ; i++) cin>>a[i] ;

    build(1,0,n-1) ; 
    while(m--)
    {
        int b, c, d ; cin>>b>>c>>d ; 

        if(b == 1)
        {
            update(1,0,n-1,c,d) ; 
        }
        else
        {
            cout<<sum(1,0,n-1,c,d-1)<<"\n" ; 
        }
    } 
}   
