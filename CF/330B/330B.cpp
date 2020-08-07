#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout); 
    int n,m; cin>>n>>m;
    int a[n+1]={};
    int e = 0; 
    for(int i=1;i<=m;i++)
    {
        cin>>e;
        a[e] = 1;
        cin>>e;
        a[e] = 1;
    }

    for(int i = 1;i<=n;i++)
    {
        if(a[i]==0)
        {
            e = i;
            break;
        }
    }

    cout<<n-1<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(i==e) continue;
        cout<<e<<" "<<i<<"\n";
    }

}   
