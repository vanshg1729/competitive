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
   
    int n ,q ; cin>>n ; 
    int a[n+1] = {} ; 
    for(int i = 1 ;i<=n ; i++) cin>>a[i] ;
    
    sort(a,a+n+1) ;
    cin>>q ;
    
    while(q--)
    {
    	int m ; cin>>m ; 

    	int i = 1 , j = n ;

    	while(i<j)
    	{
    		if(j-i==1) break ;
            int mid = (i+j)/2 ;

            if(a[mid] > m) j = mid -1;
            else i = mid ;
    	}

    	int ans = 0 ;
    	if(a[j]<=m) ans = j ;
    	else if(a[i]<=m) ans = i ;

    	cout<<ans<<"\n" ;
    }
}
