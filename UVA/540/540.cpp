#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);

    int t ; int k = 0 ; 

    while(cin>>t)
    {
        k++ ;
        if(t==0) break ;
        queue<int> list = {} ;  

        map<int,int> m = {} ;
        
        int n ; 
        for(int i = 1 ; i<=t ;i++)
        {
            cin>>n ;
            for(int j = 1 ;j<=n ;j++)
            {
                int b ; cin>>b ; 
                m[b] = i ; 
            }
        }

        queue<int> q[1010] = {} ; 

        string s ;
        
        cout<<"Scenario #"<<k<<"\n" ;
        while(cin>>s)
        {
            if(s == "STOP") break ; 

            if(s == "DEQUEUE")
            {
                int b = list.front() ; 

                cout<<q[b].front()<<"\n" ;

                q[b].pop();

                if(q[b].empty()) list.pop() ; 
            }
            else
            {
                int c ; cin>>c ; 

                int b = m[c] ; 

                if(q[b].empty()) list.push(b) ;
                q[b].push(c) ; 
            }
        }

        cout<<"\n" ;
    }        
}   
