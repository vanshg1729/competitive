#define ll long long
#define fr first
#define sc second
const int maxn = 100010;
vector<int> adj[maxn] = {};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        int n,p; cin>>n>>p;
        int m = 2*n+p;
        for(int i =1;i<=n;i++)
        {
            if(!m) break;
            for(int j = i+1;j<=n;j++)
            {
                if(!m) break;
                cout<<i<<" "<<j<<"\n";
                m--;
            }
        }
    }
    
}   

