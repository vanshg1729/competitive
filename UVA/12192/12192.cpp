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
    
    int n , m ;

    while(cin>>n>>m and n*m!=0)
    {
        int grid[500][500] = {} ; 

        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                cin>>grid[i][j] ;
            }
        }

        int q ; cin>>q ;

        while(q--)
        {
            int a , b ; cin>>a>>b ; 

            int max_size = 0 ; 

            for(int i = 0 ; i<n ; i++)
            {
                 int k = lower_bound(grid[i],grid[i]+m , a) - grid[i] ; 

                for(int j = max_size ; j<n ;j++)
                {
                    if(i+j>= n or k+j >=m or b < grid[i+j][k+j]) break ; 

                    max_size = max(max_size , j+1) ; 
                }
            }

            cout<<max_size<<"\n" ;
        }

        cout<<"-"<<"\n" ; 
    }    
}
