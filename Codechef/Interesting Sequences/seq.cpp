#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

bool check(pair<int,int> a[] , int n , int l , int k  )
{
    int dp[n+10] = {} ; 
    for(int i = 0 ; i<=n ; i++) dp[i] = 1 ;

    for(int i = 1 ;i<=n ; i++)
    {
        for(int j = 1 ; j < i ;j++)
        {
            if(abs(a[i].sc - a[j].sc ) >=k )
            {
                dp[i] = max(dp[i], dp[j] + 1 ) ;
            }
        } 

        if(dp[i] >= l) return 1 ;    
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
        int n , l ; 
        cin>>n>>l ;
        pair<int,int> a[n+10] = {} ;

        for(int i = 1 ; i<=n ;i++)
        {
            cin>>a[i].fr ;
            a[i].sc = i ;
        }

        sort(a,a+n+1) ;

        int low = 0 ;
        for(int i = 1 ; i<=n ;i++)
        {
            for(int j = i+1 ; j<=n ;j++)
            {
                if(a[i].fr != a[j].fr) break ;
                low = max(abs(a[i].sc - a[j].sc), low) ;
            }
        }

        int left = low , right = n-1 ;

        while(left < right)
        {
            int mid = (left + right +1)/2 ;

            if(check(a,n,l,mid)) left = mid ;
            else right = mid - 1 ; 
        }

        cout<<left<<"\n" ;
    }

}  
