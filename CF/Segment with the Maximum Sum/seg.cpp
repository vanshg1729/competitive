//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5) + 10 ;
ll a[maxn] = {} ;
int n ,m ; 

struct data
{
    ll sum , pref, suff , ans ; 
}; 

data t[4*maxn] = {} ; 

data make_data(ll val)
{
    data res  ; 
    res.sum = val ; 
    res.pref = res.suff = res.ans = max((ll)0,val) ; 
    return res ; 
}

data combine(data l , data r)
{
    data res  ; 

    res.sum = l.sum + r.sum ;
    res.pref = max(l.pref , l.sum + r.pref) ; 
    res.suff = max(r.suff , r.sum + l.suff) ; 
    res.ans = max(max(l.ans,r.ans),l.suff + r.pref) ; 

    return res ;  
}

void build(int v , int l , int r)
{
    if(l == r)
    {
        t[v] = make_data(a[l]) ; 
    }
    else
    {
        int m = (l+r)/2 ;
        build(2*v,l,m) ; 
        build(2*v+1,m+1,r) ; 

        t[v] = combine(t[2*v],t[2*v+1]) ; 
    }
}

void update(int v , int tl , int tr , int pos , int num)
{
    if(tl == tr)
    {
        t[v] = make_data(num) ; 
    }
    else
    {
        int tm = (tl+tr)/2 ; 

        if(pos<=tm) update(2*v,tl,tm , pos,num) ; 
        else update(2*v+1,tm+1,tr, pos, num) ; 

        t[v] = combine(t[2*v],t[2*v+1]) ; 
    }
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
    
    cout<<t[1].ans<<"\n" ; 
    while(m--)
    {
        ll b , c ;
        cin>>b>>c ;  

        update(1,0,n-1,b,c) ; 

        cout<<t[1].ans<<"\n" ; 
    } 
}   
