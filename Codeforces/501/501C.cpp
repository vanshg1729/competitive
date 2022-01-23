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
   // freopen("input.txt","r", stdin);
   // freopen("output.txt","w",stdout);
    
    int n ; cin>> n ; 
    int deg[n+1] = {} ; 
    int xo[n+1] = {} ;
    int sum = 0 ;  
    for(int i = 0;i<n ; i++)
    {
    	cin>>deg[i]>>xo[i]; 
    	sum+= deg[i] ;  
    }
    
    cout<<sum/2<<"\n" ; 
    queue<int> q = {} ; 
    for(int i = 0 ;i<n; i++)
    {
    	if(deg[i] == 1)
    	{
    		q.push(i);
    	}
    }

    while(!q.empty())
    {
    	int b = q.front() ; q.pop() ; 
        if(deg[b]!= 1) continue ; 
        
        int c = xo[b] ;
        deg[c]-- ; 
        if(deg[c] == 1) q.push(c) ; 

        xo[c]^=b ;
        cout<<b<<" "<<c<<"\n";   
    }
    
}
