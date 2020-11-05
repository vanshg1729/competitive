//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5) + 10 ; 
int n , m ;
pair<int,int> t[4*maxn] = {} ; 
int a[maxn] = {} ; 

pair<int,int> combine(pair<int,int> a , pair<int,int> b)
{
    if(a.fr<b.fr) return a ; 
    else if(a.fr>b.fr) return b ; 

    return {a.fr,a.sc+b.sc} ; 
}

void build(int v , int l , int r)
{
    if(l == r)
    {
        t[v] = {a[l],1} ; 
    }
    else
    {
        int m = (l+r)/2 ; 
        build(2*v,l,m) ; 
        build(2*v+1,m+1,r) ; 

        t[v] = combine(t[2*v],t[2*v+1]) ; 
    }
}

void update(int v, int tl , int tr , int pos , int num)
{
    if(tl == tr)
    {
        t[v] = {num,1} ; 
    }
    else
    {
        int tm = (tl+tr)/2 ; 

        if(pos<=tm) update(2*v,tl,tm,pos,num) ; 
        else update(2*v+1,tm+1,tr,pos,num) ; 

        t[v] = combine(t[2*v],t[2*v+1]) ; 
    }
}

pair<int,int> get_min(int v , int tl , int tr , int l , int r)
{
    if(l>r) return {INT_MAX,0} ; 

    if(l == tl and r == tr)
    {
        return t[v] ; 
    }

    int tm = (tl+tr)/2 ; 

    auto b = get_min(2*v,tl,tm, l , min(tm,r)) ; 
    auto c = get_min(2*v+1,tm+1,tr,max(tm+1,l),r) ; 
    return combine(b,c) ; 
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
        int type , l , r ; cin>>type>>l>>r ; 

        if(type == 1)
        {
            update(1,0,n-1,l,r) ; 
        }
        else
        {
            auto ans = get_min(1,0,n-1,l,r-1) ; 
            cout<<ans.fr<<" "<<ans.sc<<"\n" ;  
        }
    }
 
}   
