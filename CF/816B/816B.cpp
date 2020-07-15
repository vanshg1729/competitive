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
    int maxt = 200000;
    int n,k,q;
    cin>>n>>k>>q;
    int diff[maxt+10]={};
    for(int i=0;i<n;i++)
    {
        int a ,b; cin>>a>>b;
        diff[a]++; diff[b+1]--;
    }

    for(int i=1;i<=maxt;i++) diff[i]+=diff[i-1];

    int p[maxt+10]={};
    if(diff[0]>=k) p[0]++;

    for(int i=1;i<=maxt;i++) 
    {
        p[i] = p[i-1];
        if(diff[i]>=k) p[i]++;
    }

    for(int i=0;i<q;i++)
    {
        int a,b; cin>>a>>b;
        cout<<p[b]-p[a-1]<<endl;
    } 
}
