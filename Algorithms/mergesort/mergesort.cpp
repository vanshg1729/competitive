vector<int> v = {} ; 

int mer(int l, int m , int r)
{
    queue<int> q ; 

    int i = l , j = m +1 ; 

    while(i<=m or j<=r)
    {
        if(i>m or (i<=m and j<=r and v[i]>v[j]))
        {
            q.push(v[j]) ; j++ ;
            ans+= (ll)m-i+1 ;
        }
        else
        {
            q.push(v[i]) ; i++ ;
        }
    }

    for(int i = l ; i<= r; i++)
    {
        v[i] = q.front() ; q.pop() ;
    }

    return 0 ;
}


int sort(int l, int r)
{
    if(l==r) return 0 ;
    if(r-l==1)
    {
        if(v[l]>v[r]){ swap(v[l],v[r]) ; ans++ ; } 
        return 0 ;
    } 

    int m = (l+r)/2 ; 
    sort(l,m) ; sort(m+1,r) ;
    
    mer(l,m,r) ;
    return 0 ; 
}
