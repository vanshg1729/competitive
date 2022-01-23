#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R,B,G; cin>>R>>B>>G;
    int ans = R/3 + B/3 + G/3;
    int r = R%3, b = B%3, g = G%3;
    int rem = min(r,min(b,g));
    ans+=rem;
    if(rem == 0 and r + b + g == 4 and R and B and G) ans++;
    cout<<ans;
}
