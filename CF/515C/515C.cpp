#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v[10] = 
    {
        {},{},{2},{3},
        {2,2,3},{5},{3,5},{7},
        {2,2,2,7},{7,3,3,2}
    };

    
    int n; cin>>n;
    vector<int> fin = {};
    for(int i = 1; i <= n; i++){
        char a; cin>>a;
        int dig = a-'0';
        for(auto u : v[dig]) fin.push_back(u);
    }

    sort(fin.begin(),fin.end());
    for(int i = fin.size()-1; i >=0; i--) cout<<fin[i];
}
