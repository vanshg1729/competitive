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
//    freopen("input.txt","r", stdin);
 //   freopen("output.txt","w",stdout);
    
    int t ; cin>>t ;

    while(t--)
    {
        int n ; cin>>n ; 
        vector<pair<int,int> > low = {}, upp = {} ;
        int point[n+1] = {} ;

        for(int i = 1 ;i<=n ;i++)
        {
            int x,y ; cin>>x>>y ; 
            low.push_back({x,i}) ;
            upp.push_back({y,i}) ;
        }

        sort(low.begin(),low.end()) ;
        sort(upp.begin(),upp.end()) ;

        for(int i = 0 ;i<n ;i++)
        {
            point[low[i].sc] += n-i-1 ;
            point[upp[i].sc] += i ;
        }
        
        for(int i = 1 ;i<=n ;i++) cout<<point[i]<<" "; 

        cout<<"\n" ;
    }
}
i
