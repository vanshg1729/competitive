#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n,k; cin>>n>>k;
    vector<int> v;

    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            v.push_back(i);
            n/=i;
        }
    }

    if(n>=2) v.push_back(n);

    if(v.size()<k)
    {
        cout<<-1; return 0;
    }

    while(v.size()>k)
    {
        int m = v.size();
        int a = v[m-1];
        v.pop_back();
        v[m-2]*=a;
    }

    for(int i=0;i<k;i++) cout<<v[i]<<" ";

}
