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
    //freopen("input.txt","r", stdin) ;
    //freopen("output.txt","w",stdout);

    string s ; cin>>s ; 
    s = " " + s ; 

    int n = s.size() ; n-- ;

    vector<int> pos[30] = {} ; 
    int id[30] = {} , dp[n+10] = {} ; 
    pair<int,int> p[n+10] = {} ; 

    for(int i = 1 ; i<=n ; i++)
    {
        int j = s[i] -'a' ;
        pos[j].push_back(i) ;
    }

    for(int i = 0 ;i<26 ;i++)
    {
        id[i] = pos[i].size() ;
        pos[i].push_back(n+1) ;
    }

    for(int i = n ; i>0 ;i--)
    {
        dp[i] = INT_MAX ; 
        for(int j = 0 ; j<26 ; j++)
        {
            while(id[j] > 0 and pos[j][id[j]-1] >=i) id[j]-- ;

            int k = pos[j][id[j]];
            if(k == n) continue ;

            if( dp[i] > dp[k+1]+1)
            {
                dp[i] = dp[k+1] + 1 ;
                p[i].fr = k+1 ;
                p[i].sc = j ;
            } 
        }
    }  

    string ans = "" ;

    int i = 1 ;

    while(i <=n)
    {
        char c = 'a' + p[i].sc ;
        ans+=c ;

        i = p[i].fr ;
    }

    cout<<ans;

}   
