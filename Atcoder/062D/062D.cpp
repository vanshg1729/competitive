#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s; cin>>s;

    int ans = 0;
    for(int i = 0; i < s.size(); i++){

        if(s[i] == 'g'){
            if(i % 2) ans++;
        }
        else{
            if(i%2 == 0) ans--;
        }
    }

    cout<<ans;
}
