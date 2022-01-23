#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,5)+10 ; 
int n,q ; 
int p[maxn] = {} , size[maxn] = {} , r[maxn] = {} ; 

int get(int a)
{
    return p[a] = (p[a]==a ? a : get(p[a])) ; 
}

int unio(int a, int b)
{
    a = get(a) ; 
    b = get(b) ; 
    
    if(a == b) return 0 ; 
    if(r[a] == r[b]) r[a]++ ; 

    if(r[a]>r[b])
    {
        p[b] = a ; 
        size[a]+=size[b] ; 
    }
    else
    {
        p[a] = b ; 
        size[b]+=size[a] ; 
    }

    return 0 ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>n>>q ; 

    for(int i = 1 ; i<= n ;i++)
    {
        p[i] = i ; 
        size[i] = 1 ; 
    }
    
    while(q--)
    {
        char s ; cin>>s ; 
        
        int a , b ;

        if(s == 'Q')
        {
            cin>>a ; 
            cout<<size[get(a)]<<"\n" ; 
        }
        else
        {
            cin>>a>>b ; 
            unio(a,b) ;        
        } 
    }

    return 0 ; 
}   
