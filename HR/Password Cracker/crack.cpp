#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

const int maxn = 2010 ; 
string a[maxn] = {} , s ; 
int n ; 
int p[maxn] = {} ; 

int attempt(int r)
{
    if(p[r]!=-1) return p[r] ; 
    p[r] = 0 ; 
    for(int i = 1 ; i<=n ; i++)
    {
        if(a[i].size() > r) continue ; 

        string b = s.substr(r-a[i].size()+1 , a[i].size()) ; 

        if(b == a[i])
        {
            int c = r-a[i].size() ; 
            if( attempt(c) )
            {
                p[r] = i ; 
                return 1 ; 
            }
        }
    }

    return 0 ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);
    
    int T ; cin>>T ; 

    while(T--)
    {
        cin>>n ;

        for(int i = 1 ; i<=n ; i++) cin>>a[i] ; 

        cin>>s ; 

        s = " " + s ;  
        memset(p , -1 , sizeof(p)) ; 

        p[0] = 1 ;
        if(attempt(s.size()-1) )
        {
            int i = s.size() -1 ; 
            stack<int> ans; 

            while(i>0)
            {
                ans.push(p[i]) ; 

                i -= a[p[i]].size() ; 
            }

            while(!ans.empty())
            {
                cout<<a[ans.top()] ;
                ans.pop() ;
                if(ans.size()) cout<<" " ; 
            }
        }
        else cout<<"WRONG PASSWORD" ;

        if(T) cout<<"\n" ;           
    }
}   
