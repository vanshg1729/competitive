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
    
    string s;
    while(cin>>s)
    {
        deque<string> de;
        string home="";
        int n = s.size();
        int j = 1;
        for(int i=0;i<n;i++)
        {
           if(s[i]=='[')
           {

             if(j==2)
             {
               if(home.size()>0) de.push_front(home);
               home = "";
             }
             j = 2;
             continue;
           }

           if(s[i]==']')
           {

             if(j==2)
             {
                if(home.size()>0) de.push_front(home);
                home = "";
             }
             j = 1;
             continue;
           }
           
           if(j==1)
           {
             de.push_back(s.substr(i,1));
           }
           else
           {
             home+=s[i];
           }
        }

        if(home.size()>0) de.push_front(home);

        for(int i=0;i<de.size();i++) cout<<de[i];

        cout<<"\n";
    }  
}   
   



