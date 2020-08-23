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
   // freopen("input.txt","r", stdin);
   // freopen("output.txt","w",stdout);
    int n,m,v; cin>>n>>m>>v;
    int k = (n*(n-1))/2 - n+2;
    if(m<n-1 or m>k)
    {
        cout<<-1;
        return 0;
    }

    for(int i = 1;i<=n;i++)
    {
        if(i==v) continue;
        cout<<v<<" "<<i<<"\n";
        m--;
    }

    int b = (v+1)%n;
    if(b==0) b = n;

    
    for(int i = 1;i<=n;i++)
    {
        if(i==b or i== v) continue;
        if(!m) break;
        for(int j = i+1;j<=n;j++)
        {
            if(!m) break;
            if(j == b or j== v) continue;
            cout<<i<<" "<<j<<"\n";
            m--;
        }
    }
    
}   

