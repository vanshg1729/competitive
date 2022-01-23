    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        //freopen("input.txt","r", stdin);
        //freopen("output.txt","w",stdout);
        int n; cin>>n;
        string val,tol;
        cin>>val>>tol;
        int mat[27][27]={};
        vector<pair<int,int> > edge;
     
        for(int i=0;i<n;i++)
        {
        	if(val[i]==tol[i]) continue;
        	mat[val[i]-'a'][tol[i]-'a'] = 1;
        	mat[tol[i]-'a'][val[i]-'a'] = 1;
        }
     
       int seen[27] = {};
       
       for(int i=0;i<26;i++)
       {
       	  if(seen[i]) continue;
          
          stack<int> s;
          s.push(i);
          seen[i] = 1;
          while(!s.empty())
          {
          	 int a = s.top(); s.pop();
     
          	 for(int j = 0;j<26;j++)
          	 {
                 if(mat[a][j] and !seen[j] )
                 {
                 	edge.push_back({i,j});
                 	s.push(j);
                 	seen[j] = 1;
                 }
          	 }
          }
       }
     
     
       cout<<edge.size()<<"\n";
     
       for(auto u :edge)
       {
       	  char one = 'a'+u.first;
       	  char two = 'a' + u.second;
       	  cout<<one<<" "<<two<<"\n";
       }
    }  
