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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    vector<int> res = {v[0]};

    for(int i=0;i<n;i++)
    {
        for(int j =0;j<31;j++)
        {
            int x = v[i]-(1<<j);
            int y = v[i]+(1<<j);

            bool isx = binary_search(v.begin(),v.end(),x);
            bool isy = binary_search(v.begin(),v.end(),y);
            if(isx and isy and res.size()<3)
            {
                res = {x,v[i],y};
            }
            else if(isy and res.size()<2)
            {
                res = {v[i],y};
            }
        }
    }

    cout<<res.size()<<endl;
    for(auto a:res)
    {
        cout<<a<<" ";
    }

}  

   

