// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5)+10 ; 
int n , m ; 
int a[maxn] = {} , t[4*maxn] = {} ; 

void build(int v , int l , int r)
{
    if(l == r)
    {
        t[v] = a[l] ; 
    }
    else
    {
        int m = (l+r)/2 ; 

        build(2*v, l , m) ; 
        build(2*v+1, m+1 , r) ; 

        t[v] = max(t[2*v],t[2*v+1]) ; 
    }
}

void update(int v , int tl , int tr , int pos , int num)
{
    if(tl == tr)
    {
        t[v] = num ; 
    }
    else
    {
        int tm = (tl+tr)/2 ; 

        if(pos<=tm) update(2*v, tl , tm , pos , num) ; 
        else update(2*v+1, tm+1, tr , pos , num) ; 

        t[v] = max(t[2*v], t[2*v+1]) ;
    }
} 

int find(int v , int l , int r , int num)
{
    if(l == r)
    {
        if(t[v]>=num) return l ; 
        else return -1 ; 
    } 

    int m = (l+r)/2 ; 

    if(t[2*v] >= num) return find(2*v , l , m , num) ; 
    else if(t[2*v+1]>= num) return find(2*v+1 , m+1 , r , num) ; 

    return -1 ; 
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    int n ,m ; cin>>n>>m ; 

    for(int i = 0 ; i<n ; i++) cin>>a[i] ; 

    build(1 , 0 , n-1 ) ; 

    while(m--)
    {
        int type , b ,c ; cin>>type ; 

        if(type == 1 )
        {
            cin>>b>>c ; 

            update(1, 0 , n-1 , b , c ) ; 
        }
        else
        {
            cin>>c ; 

            cout<<find(1 , 0 , n-1 , c)<<"\n" ; 
        }
    } 

}   
