#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

bool comp(string s1,string s2)
{
    string a = s1+s2 , b = s2 + s1 ;
    return a<b ;    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int n ; cin>>n ;
    string a[n] = {} ;
    for(int i = 0 ;i<n ;i++) cin>>a[i] ;

    sort(a,a+n,comp) ;
    for(int i = 0 ;i<n ;i++) cout<<a[i]  ; 

}
