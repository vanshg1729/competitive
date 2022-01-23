#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

struct data{
    string str , ch ; 

    int pos ;
};

data make(string s, char c , int po)
{
    data b  ; 
    b.str = s ; 
    b.ch = c ; 
    b.pos = po ; 
    return b ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin) ; 
    //freopen("output.txt","w",stdout);

    string s, t ; cin>>s>>t ; 

    int n , m ; n = s.size() , m = t.size() ;

    int dp[n+10][m+10] = {} , p[n+10][m+10] = {} ; 

    s = " " + s ; t = " " + t ; 

    for(int j = 1 ; j<=m ; j++)
    {
        dp[0][j] = j  ;
        p[0][j] = 4 ; 
    }

    for(int i = 1 ; i<=n ;i++)
    {
        dp[i][0] = i ; 
        p[i][0] = 3 ; 
    }


    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=m ; j++)
        {
            dp[i][j] = INT_MAX ; 

            if(s[i] == t[j])
            {
                dp[i][j] = dp[i-1][j-1] ; 

                p[i][j] = 1 ; 
                continue ;
            }

            if(dp[i-1][j-1]+1 < dp[i][j])
            {
                dp[i][j] = dp[i-1][j-1]+1 ;

                p[i][j] = 2 ; // rep j t[j] 
            }

            if(dp[i-1][j] +1 < dp[i][j])
            {
                dp[i][j] = dp[i-1][j] + 1 ; 

                p[i][j] = 3 ; // del j+1
            }

            if(dp[i][j-1] < dp[i][j])
            {
                dp[i][j] = dp[i][j-1] + 1 ; 

                p[i][j] = 4 ; // insert j t[j]
            }
        }
    }


    int i = n , j = m ; 

    stack<data> q ;

    while(i or j)
    {
        if(p[i][j] == 1)
        {
            i-- ; j-- ; 
            continue ; 
        }
        else if(p[i][j] == 2)
        {
            string b = "REPLACE" ; 
            data c = make(b , t[j] , j) ; 
            q.push(c) ; i-- ; j-- ;
        }
        else if(p[i][j] == 3)
        {
            string b = "DELETE" ; 
            data c = make(b , t[j] , j+1) ; 
            q.push(c) ; 
            i-- ; 
        }
        else
        {
            string b = "INSERT" ; 
            data c = make(b , t[j] , j) ;
            q.push(c) ;  
            j-- ;
        }
    } 

    cout<<q.size()<<endl ;
    while(!q.empty())
    {
        data b = q.top() ; 

        q.pop() ; 

        if(b.str!= "DELETE") cout<<b.str<<" "<<b.pos<<" "<<b.ch<<endl ;
        else cout<<b.str<<" "<<b.pos<<endl ;  
    }
}   
