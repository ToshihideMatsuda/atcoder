void dikstra(int start) {
    for (int i = 1; i < n+1; i ++) cost[i] = INT_MAX;

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int, int>>> Q;
    
    Q.push(pair(0,start));
    cost[start]=0;
    
    while(Q.size() > 0) {
        auto from = Q.top();Q.pop();
        auto to = G[from.second];
        for(int i = 0; i < to.size(); i++){
            int current = cost[to[i].second];
            int better = to[i].first + from.first;
            if(current > better){
                cost[to[i].second] = better;
                Q.push(pair(better,to[i].second));
            }
        }
        
    }

}
