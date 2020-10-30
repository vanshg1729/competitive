#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
const int maxn = pow(10,6)+10 ; 
int t , n ; 
int p[maxn] = {} ,r[maxn] = {} ; 

int get(int a)
{
    return p[a] = (p[a] == a ? a : get(p[a])) ; 
}

int uni(int a , int b)
{
    a = get(a) ; 
    b = get(b) ; 

    if(a == b) return 0 ; 

    if(r[a] == r[b]) r[a]++ ; 

    if(r[a]>r[b])
    {
        p[b] = a ; 
    }
    else p[a] = b ; 

    return 0 ; 
}

int conver(string s)
{
    int k = 0 ; 
    
    for(int i = 0; i<s.size() ; i++)
    {
        k*=10 ;
        k+= s[i] - '0' ; 
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

    cin>>t ; 
    cin>>n ; 

    while(t--)
    {
        int yes = 0 , no = 0 ; 

        for(int i = 1 ; i<=n ; i++)
        {
            p[i] = i ; 
            r[i] = 0 ; 
        }

        string c ; 

        while(cin>>c)
        { 
            if(c!="c" and c!="q")
            {
                n = conver(c) ; 
                break ; 
            }

            int a, b ; cin>>a>>b;

            if(c == "c")
            {
                uni(a,b) ; 
                continue ; 
            } 

            if(get(a) == get(b)) yes++ ; 
            else no++ ; 
        }

        cout<<yes<<","<<no<<"\n";
        if(t!=0) cout<<"\n" ;   
    }

}   
