#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int lines = 0 ; 
string s = "" ; 
vector<int> v = {} ; 

bool check(int wid)
{
    int l = 1 ; 
    int j = 0 ;
    int sum = 0 ; 

    while(j<v.size())
    {
        if(sum == 0 and sum+v[j]>wid) return 0 ; 

        if(sum+v[j]<=wid)
        {
            sum+=v[j] ; 
            j++ ; 
        }
        else
        {
            sum = 0 ; 
            l++ ;
        }
    } 

    return l <= lines ; 
}


int bin()
{
    int k = 0 , d = s.size() ; 

    while(1)
    {
        if(k+d<=s.size() and !check(k+d)) k+=d ; 

        if(d == 1) break ; 

        d = d/2 + d%2 ; 
    }
    
    k++ ; 
    return k ; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>lines ; 
    v.push_back(0) ;    
    
    cin>>s ; 
    string a = "" ; 
    
    while(cin>>a)
    {
       s+= " " + a ; 
    }
    
    int j = -1 ; 
    for(int i = 0 ; i<s.size() ; i++)
    {
        if(s[i] == '-' or s[i] == ' ' or i == s.size()-1)
        {
            v.push_back(i-j) ; 
            j = i ; 
        }
    }
    
    cout<<bin();  
}
