#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    long long n,m;
    while(cin>>n)
    {
        cin>>m;
        long long k = m;
        vector<pair<long long,long long> > v;
        for(int i=2;i*i<=m;i++)
        {
            if(m%i==0)
            {
                v.push_back({i,0});
                long long l = v.size();
                while(m%i==0)
                {
                    m/=i;
                    v[l-1].second++;
                }
            }
        }

        if(m>1) v.push_back({m,1});

        bool b = true;

        for(int i=0;i<v.size();i++)
        {
            long long a = v[i].first;
            long long freq = 0;
            long long c = a;
            while(c<=n)
            { 
                freq+=n/c;
                c*=a;
            }

            if(freq<v[i].second) b = false;
        }

        if(b) cout<<k<<" divides "<<n<<"!"<<endl;
        else cout<<k<<" does not divide "<<n<<"!"<<endl;
    }

}
