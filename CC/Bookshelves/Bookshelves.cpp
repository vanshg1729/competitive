#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int solve(vector<int> a ,vector<int> b ,int k)
{ 
    priority_queue<int> big , small ; 

    for(auto u : a) big.push(u) ; 
    for(auto u : b ) small.push(-u) ; 

    for(int i = 1; i<=k ;i++)
    {
        if(big.top() > -small.top())
        {
            int u = big.top() , v = small.top() ;

            big.pop() ; small.pop() ;
            big.push(-v) ; small.push(-u) ; 
        }
    } 
    
    return big.top() ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int n,k ; cin>>n>>k ;

    vector<int> a , b ; 
    int big = 0 ;

    for(int i = 1 ;i<=n;i++) 
    {
        int u ; cin>>u ; 
        a.push_back(u) ;
        big = max(u,big) ; 
    }

    for(int i = 1 ;i<=n ;i++)
    {
        int u ; cin>>u ; 
        b.push_back(u) ; 
        big = max(u,big) ; 
    }

    cout<<min(solve(a,b,k),solve(b,a,k)) + big ; 
 }
