#include <bits/stdc++.h>
using namespace std;
#define ll long long

string convert(int j)
{
  string in = "";
  while(j>0)
  {
    int rem = j%10;
    j/=10;
    char c = '0'+rem;
    in+=c;
  }
  reverse(in.begin(),in.end());
  return in;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout); 
    map<string,int> m;
    int n; cin>>n;
    string b[n+1]={};
    for(int i=1;i<=n;i++) b[i] = convert(i);

    for(int i=1;i<=n;i++)
    {
        string s ; cin>>s;
        if(!m.count(s))
        {
           m[s] =0;
           cout<<"OK"<<"\n";
        }
        else
        {
            m[s]++;
            cout<<s+b[m[s]]<<"\n";
        }
    }
}   
   
