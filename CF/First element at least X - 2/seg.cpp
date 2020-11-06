// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5)+10 ; 
int n , m , a[maxn] = {} ;
int t[4*maxn] = {} ; 

void build(int v , int l , int r)
{
    if(l == r)
    {
        t[v] = a[l] ; 
    }
    else
    {
        int m = (l+r)/2 ; 
        build(2*v, l , m); 
        build(2*v+1 , m+1 , r) ; 
        t[v] = max(t[2*v] , t[2*v+1]) ; 
    }
}

void update(int v , int l , int r , int pos , int num)
{
    if(l == r)
    {
        t[v] = num ; 
    }
    else
    {
        int m = (l+r)/2 ; 

        if(pos <= m) update(2*v, l , m , pos , num) ; 
        else update(2*v+1 , m+1 , r , pos , num) ;

        t[v] = max(t[2*v], t[2*v+1]) ; 
    }
}

int query(int v , int tl, int tr , int l , int r , int x )
{
    if(tl > r or tr < l) return -1 ;

    if(tl >= l and tr <= r)
    {
        if(t[v] < x) return -1 ; 

        while( tl != tr)
        {
            int tm = (tl+tr)/2 ; 
            if(t[2*v] >= x)
            {
                v = 2*v ; 
                tr = tm ; 
            }
            else
            {
                tl = tm+1 ; 
                v = 2*v+1 ; 
            }
        }

        return tl ; 
    }

    int tm = (tl + tr )/2 ; 
    int rs = query(2*v , tl , tm , l , r , x) ; 
    if(rs != -1) return rs ; 
    return query(2*v+1 , tm+1 , tr , l , r , x) ; 

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

    build(1 , 0 , n-1) ; 
    while(m--)
    {
        int t , b , c ; cin>>t>>b>>c ; 

        if(t == 1)
        {
            update(1 , 0 , n-1 , b , c) ; 
        }
        else
        {
            cout<<query(1 , 0 , n-1 , c , n-1 , b)<<"\n" ; 
        }
    }

}   
