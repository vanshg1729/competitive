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
    multiset<double> m;
    int n; cin>>n;

    double t ; cin>>t;
    m.insert(t);

    auto a = m.begin();
    auto b = m.begin();
    double ans = *a;
    
    printf("%.1f\n", ans);

    for(int i=2;i<=n;i++)
    {
        cin>>t;
        m.insert(t);
        
        //cout<<i<<":"<<*a<<" ,"<<*b<<endl;
        if(i%2)
        {
            if(t < *b)
            {
                b--;
            }

            a = b;

            ans = *b;
            printf("%.1f\n", ans);
        }
        else
        {
            if(t<*b)
            {
                a--;
            }
            else
            {
                b++;
            } 

            ans = (*a+*b)/2;
            printf("%.1f\n", ans);

        }

        //cout<<i<<":"<<*a<<" ,"<<*b<<endl;
    }
}   

