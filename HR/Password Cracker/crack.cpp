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
    if(p[r] or !r) return 1 ;  
    for(int i = 1 ; i<=n ; i++)
    {
        if(a[i].size() > r) continue ; 

        string b = s.substr(r-a[i].size()+1 , a[i].size()) ; 

        if(b == a[i])
        {
            if(r-a[i].size()!=0 and p[r-a[i].size()] or r == a[i].size())
            {
                p[r] = i ;
                return 1 ; 
            }

            if( attempt(r - a[i].size() ) )
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
    freopen("input.txt","r", stdin) ;
    freopen("output.txt","w",stdout);
    
    int T ; cin>>T ; 

    while(T--)
    {
        cin>>n ;

        for(int i = 1 ; i<=n ; i++) cin>>a[i] ; 

        cin>>s ; 

        s = " " + s ;  
        memset(p , 0 , sizeof(p)) ; 

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
                cout<<a[ans.top()]<<" " ; 
                ans.pop() ; 
            }
            cout<<"\n"; 
        }
        else cout<<"WRONG PASSWORD"<<"\n" ;          
    }
}   
