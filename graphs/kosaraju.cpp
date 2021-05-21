vector<int> adj[N] , jda[N] ; 
int viz[N] ;

void dfs1(int x, vector<int> &ord){
       viz[x] = 1;
       for(auto u : adj[x]){
              if(!viz[u]){
                     dfs1(u , ord) ; 
              }
       }
       ord.push_back(x) ; 
}

void dfs2(int x, vector<int> &comp){
       viz[x] = 2 ; 
       comp.push_back(x) ; 
       for(auto u : jda[x]){
              if(viz[u] != 2){
                     dfs2(u, comp) ; 
              }
       }
}

void kosaraju(){
       vector<int> ord ; 
       
       for(int i = 0; i< n;++ i){
              if(!viz[i]){
                     dfs1(i , ord) ; 
              }
       }
       vector<vector<int> > comps; 
       while(ord.size()){
              int bk = ord.back() ; 
              ord.pop_back() ; 

              if(viz[bk] != 2){
                     vector<int> comp ; 
                     dfs2(bk,comp) ;
                     comps.push_back(comp) ; 

              }
       }
       cout << comps.size() << endl ; 
       for(auto &u : comps){
              cout << u.size() << ' ' ; 
              for(auto u2 : u){
                     cout << u2 <<" " ; 
              }
              cout << endl; 
       }
}
