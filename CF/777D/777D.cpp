#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    
    if(n==1) {cout<<s[0]; return 0;}

    for(int i=n-2;i>=0;i--)
    {
        int j =0; int len = min(s[i].length(),s[i+1].length());

        while(j<len and s[i][j]==s[i+1][j]) j++;
        if( s[i][j]>s[i+1][j] ) s[i] = s[i].substr(0,j);
    }

    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
}
