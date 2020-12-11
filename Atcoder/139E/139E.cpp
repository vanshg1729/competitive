#include <bits/stdc++.h> 
#define fr first 
#define sc second 
#define ll long long 
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    //freopen("input.txt","r",stdin) ;
    //freopen("output.txt","w",stdout) ;

    int n ; cin>>n ; 

    queue<int> q[n+10] = {} ;

    for(int i = 1 ; i<=n ;i++)
    {
        for(int j = 1 ; j<n ; j++)
        {
            int a ; cin>>a ; 
            q[i].push(a) ;
        }
    }

    bool b = 1 ; 
    int match = 0 ; 
    int days = 0 ; 

    while(b)
    {
        b = 0 ; 
        int seen[n+10] = {} ;

        for(int i = 1 ; i<=n ; i++)
        {
            if(seen[i] or q[i].empty()) continue ;
            int a = q[i].front() ;
            if(q[a].front() == i and !seen[a])
            {
                b = 1 ;
                match++ ;
                q[i].pop() ;
                q[a].pop() ;
                seen[i] = seen[a] = 1 ;
            }
        }

        if(b) days++ ;
    }

    if(match == (n*(n-1))/2) cout<<days ;
    else cout<<-1 ;

}
