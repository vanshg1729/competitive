#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
   // freopen("output.txt","w",stdout); 
    int t; cin>>t;
    while(t--)
    {
        map<int,int> m;
        int n; cin>>n;
        int dis = 0;
        int ma = 0;
        for(int i=0;i<n;i++)
        {
            int k ; cin>>k;
            if(!m.count(k))
            {
                dis++; m[k]=1;
            }
            else
            {
                m[k]++;
            }
            
            int a = m[k];
            ma = max(ma,a);
        }
        
        dis--;
        if(ma>dis) cout<<min(ma-1,dis+1)<<"\n";
        else cout<<min(dis,ma)<<"\n";
    }
}   
   
