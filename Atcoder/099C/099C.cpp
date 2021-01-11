#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<int> coin = {};
    coin.push_back(1);
    coin.push_back(0);
    coin.push_back(pow(6,6));
    for(int i = 1; i < 6; i++){
        coin.push_back(pow(6,i));
        coin.push_back(pow(9,i));
    }

    sort(coin.begin(),coin.end());

    int n; cin>>n;
    int t = 14;
    int dp[t][n+10] = {};
    for(int i = 1; i <= n; i++){
        dp[1][i] = i;
    }

    for(int i = 2; i <= 12; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][j];
            if(j - coin[i] >= 0){
                dp[i][j] = min(dp[i][j],dp[i][j-coin[i]]+1); 
            }
        }
    }

    cout<<dp[12][n];
}
