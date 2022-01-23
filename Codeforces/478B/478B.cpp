#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    long long n ,m; cin>>n>>m;
    long long min=0 ,max=0;
    max = ((n-m+1)*(n-m))/2;
    long long a = n/m;
    long long b = n%m;

    min = b*(a+1)*(a) + (m-b)*(a)*(a-1);
    min/=2;

    cout<<min<<" "<<max;
        
}
