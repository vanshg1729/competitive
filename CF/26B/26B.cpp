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
    int len = 0;
    string s ;
    cin>>s;
    stack<int> brac;
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') brac.push(1);
        if(s[i]==')' and !brac.empty())
        {
            brac.pop();
            len+=2;
        }
    }

    cout<<len;
}   
