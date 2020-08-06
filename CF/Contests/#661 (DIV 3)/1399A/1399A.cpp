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
    int t; cin >> t;
    while (t--) { 
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
 
        if (n == 1) {
            printf("YES\n");
            continue;
        }
        int b = 1;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i-1]) > 1) {
                b = 0;
                break;
            }
        }
        if (b) printf("YES\n");
        else printf("NO\n");
    }
}   
 
