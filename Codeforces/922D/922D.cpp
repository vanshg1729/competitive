#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define fr first
#define sc second

struct data
{
    int s,h;
    string str;
};
int n;

bool comp(data a, data b){
    if(a.s == 0 and b.s == 0){
        return a.str.size() < b.str.size(); 
    }
    if(a.h == 0 and b.h == 0){
        return a.str.size() > b.str.size();
    }
    if(a.h == 0) return 1;
    if(b.h == 0) return 0;

    double c = (db)a.s/a.h;
    double d = (db)b.s/b.h;
    return c > d;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    data mat[n+1] = {};

    for(int i = 0; i < n; i++){
        string a; cin>>a;
        mat[i].str = a;
        for(auto u : a){
            if(u == 's') mat[i].s++;
            else mat[i].h++;
        }
    }

    int a[5] = {};
    sort(mat,mat+n,comp);

    string fin = "";
    for(int i = 0; i < n; i++){
        fin+=mat[i].str;
    }

    int suf[fin.size()+1] = {};

    ll ans = 0;
    for(int i = fin.size()-1; i >=0; i--){
        suf[i] = suf[i+1] + (fin[i] == 'h');

        if(fin[i] == 's') ans+= (ll)suf[i+1];
    }
    
    cout<<ans;
}
