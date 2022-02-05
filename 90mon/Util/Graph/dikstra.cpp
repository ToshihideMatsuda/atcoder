#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 

#define INT_MAX  1<< 28

vector<int> G[MAX_N];

void dikstra(int start) {
    reps(i,1,N+1) cost[i] = INT_MAX;

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int, int>>> Q;
    
    Q.push(pair(0,start));
    cost[start]=0;
    
    while(Q.size() > 0) {
        auto from = Q.top();Q.pop();
        auto to = G[from.second];
        rep(i,to.size()){
            int current = cost[to[i].second];
            int better = to[i].first + from.first;
            if(current > better){
                cost[to[i].second] = better;
                Q.push(pair(better,to[i].second));
            }
        }
        
    }

}
