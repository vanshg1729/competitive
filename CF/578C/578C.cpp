    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fr first
    #define sc second
    const int maxn = 2*pow(10,6) + 10 ; 
    int n  = 0 ;
    double a[maxn] = {} ; 
     
    double weak(double x)
    {
        double ans1 = a[1]-x , sum1 = a[1]-x ; 
        double ans2 = x - a[1] , sum2 = x -a[1] ; 
     
        for(int i = 2 ;i<=n ;i++)
        {
            sum1 = max(a[i]-x,sum1+a[i]-x) ; 
            sum2 = max(-a[i]+x,sum2 -a[i]+x) ;
            ans1 = max(ans1,sum1) ; 
            ans2 = max(ans2,sum2) ;
        }
     
        return max(ans1,ans2) ;
    }
     
    double bin()
    {
        double l = -pow(10,4)-10 , r = pow(10,4)+10 ; 
     
        while(abs(weak(r)-weak(l))>=1e-6 or (r-l) >=1e-6)
        {
            double m = (r+l)/2 ; 
            if(weak(m)<weak(m+1e-11)) r = m ; 
            else l = m ; 
        }
        
        return weak(r) ; 
    }
     
    double ter()
    {
        double l = -(1e5) , r = 1e5 ; 
     
        while(1)
        {
            double m1 = l + (r-l)/3 ; 
            double m2 = r - (r-l)/3 ; 
     
            double f1 = weak(m1) ; 
            double f2 = weak(m2) ;
     
            if(r-l<1e-11 and abs(f2-f1)<1e-7) break ; 
     
            if(f1 < f2) r = m2 ; 
            else l = m1 ;
        }
     
        return weak(r) ;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //freopen("input.txt","r", stdin);
        //freopen("output.txt","w",stdout);    
        
        cin>>n ; 
     
        for(int i = 1 ;i<=n ;i++) cin>>a[i] ;
        
        printf("%.15f\n" ,ter()) ;
    }   
