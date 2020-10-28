#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    int n , m ; cin>>n>>m ; 
    
    deque<int> de ; deque<pair<int,int>> d ; 
    queue<pair<int,int> > q ;  
    for(int i = 0 ;i<n ;i++)
    {
        int a ;cin>>a ; 
        de.push_back(a) ;
    }
    
    for(int i = 1 ;i<=m ; i++)
    {
        int r , t ; cin>>t>>r ; 
        r-- ; 

        while(d.size()>0 and d[d.size()-1].fr < r) d.pop_back() ; 

        d.push_back({r,t}) ;  
    }

    for(int i = 0 ; i<d.size() ; i++) q.push({d[i].fr,d[i].sc}) ; 
    
    int a = q.front().fr , b = q.front().sc ; 

    int size = n-a-1 ;

    sort(de.begin(),de.begin()+a+1) ;

    deque<int> ans = {} ;

    for(int i = n-1 ; i> a; i--)
    {
        ans.push_front(de[i]) ;
        de.pop_back() ;  
    }

    q.pop() ; 

    while(!q.empty())
    {
        a = q.front().fr ; 
        size = de.size() - a -1 ; 

        if(b == 2)
        {
            for(int i = 0 ; i <size ;i++ )
            {
                ans.push_front(de[i]) ; 
            }
            for(int i = 0 ; i<size ; i++) de.pop_front() ;
        }
        else
        {
            for(int i = de.size()-1 ; i>a ; i--)
            {
                ans.push_front(de[i]) ; 
            }

            for(int i = de.size()-1 ; i>a ;i--) de.pop_back() ; 
        }

        b = q.front().sc ; 
        q.pop() ;

    }

    if(b == 2)
    {
        for(int i = 0 ; i<de.size() ; i++) ans.push_front(de[i]) ;
    }
    else
    {
        for(int i = de.size()-1 ;i>=0 ;i--) ans.push_front(de[i]) ;
    }
    
    for(auto u : ans) cout<<u<<" " ;


}   
