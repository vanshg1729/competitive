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
    int n,k; 
    cin>>n>>k;
    int ans[n+1]={};
    set<pair<int,int>> skill;
    set<pair<int,int>> idx;
    for(int i=1;i<=n;i++)
    {
        int a ; cin>>a;
        skill.insert({a,i});
        idx.insert({i,a});
    }

    int t = 0;
    while(!skill.empty())
    {
        auto it = skill.end(); it--;
        auto p = *it;
        pair<int,int> id = {p.second,p.first};
        
        vector<pair<int,int>> v;

        auto pos = idx.find(id);
        for(int i=0;i<=k;i++)
        {
            v.push_back(*pos);
            if(pos==idx.begin()) break;
            pos--;
        }
        
        pos = next(idx.find(id));

        for(int i=0;i<k;i++)
        {
            if(pos==idx.end()) break;
            v.push_back(*pos);
            pos++;
        }
        
        for(auto a : v)
        {
            idx.erase(a);
            skill.erase({a.second,a.first});
            ans[a.first] = t+1;
        }

        t++; t%=2;
    }

    for(int i=1;i<=n;i++) cout<<ans[i];
}   
   
