//
//  026.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/19.
//

/*
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <set>

 using namespace std;

 // Input
 int N;
 vector<int>G [100000+9];
 int colors [100000+9];

 int main() {

     cin >> N;
     
     for(int i=1;i<N+1;i++){
       colors[i]=0;
     }
     
     for(int i=1;i<N;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
     }
     
     
     int color =1;
     queue<int> Q;
     vector<int> ans1;
     vector<int> ans2;
     
     Q.push(1);
     colors[1]=color;
     ans1.push_back(1);
     
     while(Q.size()>0){
         int p = Q.front();Q.pop();
         color = -1 *colors[p];
         for(int i : G[p]){
         
             if(colors[i]==0){
             
                 Q.push(i);
                 colors[i]=color;
                 
                 if(color==1){
                     ans1.push_back(i);
                 }
                 else{
                     ans2.push_back(i);
                 }
                 
             }
         }
     }
     
     vector<int> ans=ans1;
     
     if(ans2.size() >= N/2){
         ans=ans2;
     }
     
     
     for(int i = 0; i< N/2;i++){
         cout << ans[i]<< " ";
     }
     
     return 0;
 }
 */
