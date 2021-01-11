#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

bool check(int h, int w , int n, int m){
    if(h <= n and w <= m) return true;
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m; cin>>n>>m;
    int mat[n+10][m+10] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>mat[i][j];
        }
    }

    vector<pair<int,int>> st = {},end = {};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mat[i][j]%2 == 0) continue;
            if(check(i,j+1,n,m)){
                mat[i][j]--;
                mat[i][j+1]++;
                st.push_back({i,j});
                end.push_back({i,j+1});
            }
            else if(check(i+1,j,n,m)){
                mat[i][j]--;
                mat[i+1][j]++;
                st.push_back({i,j});
                end.push_back({i+1,j});
            }
        }
    }

    cout<<st.size()<<"\n";
    for(int i = 0; i < st.size(); i++){
        cout<<st[i].fr<<" "<<st[i].sc<<" ";
        cout<<end[i].fr<<" "<<end[i].sc<<"\n";
    }    
}
