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
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
 
        string s; cin>>s;
        int a[n]={};
        int num =1;
        set<int> zer;
        set<int> one;
 
        if(s[0]=='0')
        {
            zer.insert(1);
            a[0] = 1;
        }
        else
        {
            one.insert(1);
            a[0] = 1;
        }
 
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(one.size()>=1)
                {
                    auto b = one.begin();
                    a[i] = *b;
                    one.erase(*b);
                    zer.insert(*b);
                }
                else
                {
                   a[i] = num+1;
                   num++;
                   zer.insert(num);
                }
            }
            else
            {
                if(zer.size()>=1)
                {
                    auto b = zer.begin();
                    a[i] = *b;
                    zer.erase(*b);
                    one.insert(*b);
                }
                else
                {
                    a[i] = num+1;
                    num++;
                    one.insert(num);
                }
            }
        }
 
        cout<<num<<"\n";
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
 
        cout<<"\n";
 
    }
}   
