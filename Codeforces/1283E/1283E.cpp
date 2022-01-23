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
    int m = 200000;
    int a[m+10]={};
    int b[m+10]={};
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a[x]++;b[x]++;
    }

    int min = 0, max =0,j=0,k=0;
//max
    for(int i=1;i<=n+1;i++)
    {
        if(i==j) continue;
        if(a[i]==1)
        {
            if(!a[i-1])
            {
                max++;a[i]--;
            }
            else
            {
                max++;
            }
        }
        else if(a[i]==2)
        {
            if(!a[i-1])
            {
                max+=2; a[i]--;
            }
            else if(!a[i+1])
            {
                max+=2;
                a[i+1]++; j =i+1;
            }
            else if(a[i+1])
            {
               max++; a[i+1]++;
               a[i]--;
            }
        }
        else if(a[i]>2)
        {
            if(!a[i-1] and !a[i+1])
            {
                max+=3;
                a[i+1]++; j = i+1;
            }
            else if(!a[i-1] and a[i+1])
            {
                max+=2; a[i]-=2;
                a[i+1]++;
            }
            else if(!a[i-1])
            {
                max+=2;a[i]--;

            }
            else if(!a[i+1])
            {
                max+=2;
                a[i+1]++; j = i+1;
            }
            else if(a[i+1])
            {
                max++; a[i+1]++;
                a[i]--;
            }
        }
    }
//max

    j = 0;

//min
    for(int i=1;i<=n;i++)
    {
        if(!b[i] or i==j) continue;

        if(b[i-1])
        {
            b[i]=0;
        }
        else
        {
            min+=1; b[i+1]++;
            j = i+1;
        }
    }
//min

    cout<<min<<" "<<max;        
}
