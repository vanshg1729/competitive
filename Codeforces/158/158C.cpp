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
    vector<string> v;
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a ; cin>>a;
        if(a=="pwd")
        {
            cout<<"/";
            for(auto b:v) cout<<b<<"/";
            cout<<"\n";
        }
        else
        {
            int j = -1;
            string s ; cin>>s;
            for(int k = 0;k<s.size();k++)
            {
                if(k==0 and s[k]=='/')
                {
                    v.clear();
                    j = 0;
                }
                if(s[k]=='/')
                {
                    if(j!=-1 and k-1>=0 and s[k-1]!='.') { v.push_back(s.substr(j+1,k-j-1));}
                    else if(j==-1 and k-1>=0 and s[k-1]!='.')
                    {
                       v.push_back(s.substr(0,k));
                    }
                    j = k;
                }
                else if(s[k]=='.')
                {
                    if(k-1>=0 and s[k-1]=='.')
                    {
                       v.pop_back();
                    } 
                }
                if(k==s.size()-1 and s[k]!='/' and s[k]!='.') { v.push_back(s.substr(j+1,k-j));}
            }
        }
    }



}   
