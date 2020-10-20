#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

vector<int> v = {} ;

string s  = "" , word = "" ;

int poss(int k )
{
    int a[s.size()+1] = {} ;

    for(int i = 1 ;i<=k ;i++) a[v[i]] = 1; 

    int j = 0 ; 

    for(int i = 0 ; i< s.size() ;i++)
    {
        if(a[i+1] or s[i] != word[j] ) continue ; 
        j++ ; 

        if(j == word.size()) break ; 
    }

    return j>= word.size() ; 
}

int bin()
{
    int d = s.size() ; 
    int k = 0 ; 

    while(1)
    {
        if(k+d<=s.size()  and poss(k+d) ) k+=d ; 

        if(d == 1) break ; 

        d = d/2 + d%2 ; 
    }

    return k ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>word ; 
    
    v.push_back(0) ;

    for(int i = 1 ; i<=s.size() ; i++)
    {
        int a ; cin>>a ; 
        v.push_back(a) ; 
    }
    
    cout<<bin() ;
}
