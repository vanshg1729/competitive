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

    int n; cin>>n;
    int mat[n+10] = {};
    for(int i = 1; i <= n; i++){
        cin>>mat[i];
    }

    int ans = 0;
    while(1){

        int sm = -1;
        for(int i = 1; i <= n; i++){
            if(mat[i] == 0) continue;
            if(sm == -1 or mat[i] < mat[sm]) sm =i;
        }

        if(sm == -1) break;

        ans+=mat[sm];

        for(int i = sm-1; i > 0; i--){
            if(mat[i] == 0) break;
            else mat[i]-= mat[sm];
        }

        for(int i = sm+1; i <= n; i++){
            if(mat[i] == 0) break;
            else mat[i]-=mat[sm];
        }

        mat[sm] = 0;
    }

    cout<<ans;
}
