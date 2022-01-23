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
    
    int t ; cin>>t ;

    while(t--)
    {
    	int m , n; cin>>m>>n ;

    	pair<int,int>  a[n] = {} ;

    	for(int i = 0 ;i<n ;i++)
    	{
    		cin>>a[i].fr ;
    		a[i].sc = i ;
    	}

    	sort(a,a+n) ;

        int i = 0 , j = n-1 ;

        while(i<j)
        {
        	if(a[i].fr+a[j].fr>m) j-- ;
        	else if(a[i].fr+a[j].fr<m) i++ ;
        	else break ;
        }

        cout<<min(a[i].sc,a[j].sc)+1<<" "<<max(a[i].sc,a[j].sc)+1<<"\n"; 
    }
    
}
