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
    while(cin>>n)
    {
      if(n==0) break;
      int co;
      
    // start cases with train number = n
      while(cin>>co)
      {

         if(co==0) break;

         vector<int> fin;
         int a[n+1]={};

         fin.push_back(co);
         a[1]=co;

         for(int i=2;i<=n;i++)
         {
            cin>>a[i];
            fin.push_back(a[i]);
         }

         stack<int> stat;
         stat.push(0);
         bool b = true;

         for(auto c:fin)
         {

            if(a[c]==0 and stat.top()!=c)
            {
                b = false; break;
            }

            for(int i=1;i<=c;i++)
            {
                if(a[i])
                {
                    stat.push(i);
                    a[i]=0;
                }
            }
            
            if(stat.top()==c)
            {
                stat.pop();
            }
            
         }

         if(b) cout<<"Yes"<<"\n";
         else cout<<"No"<<"\n";

      }
      // end cases with train number = n
   
      cout<<"\n";

    }
}   
   



