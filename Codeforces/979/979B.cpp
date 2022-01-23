#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int num[3] = {};
string str[3] = {};
map<char,int> m[3] = {};
int n;

void f(int i){

    int ch = 0;
    int siz = str[i].size();
    for(auto u : m[i]){
        ch = max(ch,u.sc);
    }

    if(ch + n <= siz) num[i] = ch + n;
    else{
        int t = ch + n - siz;
        if(t > 1) num[i] = siz;
        else num[i] = siz - (ch == siz);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for(int i = 0; i < 3; i++){
        cin>>str[i];
        for(auto u : str[i]){
            m[i][u]++;
        }
    }


    for(int i = 0; i < 3; i++) f(i);

    if(num[0] > num[1] and num[0] > num[2]) cout<<"Kuro";
    else if(num[1] > num[0] and num[1] > num[2]) cout<<"Shiro";
    else if(num[2] > num[0] and num[2] > num[1]) cout<<"Katie";
    else cout<<"Draw";

}
