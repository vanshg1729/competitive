    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fr first
    #define sc second
     
    const ll maxn = pow(10,12) +110;
    ll pre[4] = {} , price[4] = {} , req[4] = {} ;  
     
    ll cost(ll n )
    {
       ll ans = 0 ; 
     
       for(int i = 1 ;i<=3 ;i++)
       {
            if(n*req[i] -pre[i]>=0) ans+= (n*req[i]-pre[i])*price[i] ; 
       } 
     
       return ans ; 
    }
     
    ll bin(ll money )
    {
        ll k = 0 ; 
     
        ll d = maxn ; 
     
        while(1)
        {
            if(k+d<=maxn and cost(k+d)<= money) k+=d ; 
     
            if(d == 1) break ; 
     
            d = d/2 + d%2 ; 
        }
     
        return k ;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //freopen("input.txt","r", stdin);
        //freopen("output.txt","w",stdout);
        
        string s ; cin>>s ; 
        ll money = 0 ;
        for(int i = 1 ; i<=3 ; i++) cin>>pre[i] ;
        for(int i = 1 ; i<=3 ; i++) cin>>price[i] ; 
     
        cin>>money ;
     
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == 'B') req[1]++ ; 
            else if(s[i] == 'S') req[2]++ ; 
            else req[3]++ ;
        }
     
        cout<<bin(money) ;
    }
