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
    int n,k,q; cin>>n>>k>>q;
    int a[n+1]={};
    for(int i=1;i<=n;i++) cin>>a[i];
    
    set<int> online;
    while(q--)
    {
        int ty, id; cin>>ty>>id;
        if(ty==1)
        {
          online.insert(a[id]); 
          continue;
        }

        if(!online.count(a[id]))
        {
            cout<<"NO"<<"\n";
            continue;
        }

        auto j = online.end();
        j--;
        
        bool b = false;

        for(int i=0;i<k;i++)
        {
            if(*j==a[id])
            {
                b = true;
            }

            if(j == online.begin()) break;
            j--;
        }

        if(b) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n"; 
    }

}   
