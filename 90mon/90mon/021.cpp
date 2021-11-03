//
//  021.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/19.
//

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Input
int N, M;
int A[1 << 18], B[1 << 18];

// Graph
bool used[1 << 18];
vector<int> G[1 << 18];
vector<int> H[1 << 18];
vector<int> I;
long long cnt = 0;

void dfs(int pos){
   used[pos]=true;
   for(int i : G[pos]){
       if(used[i]==false) dfs(i);
   }
   I.push_back(pos);
}

void dfs2(int pos){
   used[pos]=true;
   for(int i : H[pos]){
       if(used[i]==false) dfs2(i);
   }
   cnt++;
}

int main() {
   // Step #1. Input
   cin >> N >> M;
   for(int i=0;i<M;i++){
       cin >> A[i] >>B[i];
   
       G[A[i]].push_back(B[i]);
       H[B[i]].push_back(A[i]);
   }
   for(int i=1; i<=N;i++){
       used[i]=false;
   }

   // Step #2. First DFS
   for(int i=1; i<=N;i++){
       if(used[i]==false) dfs(i);
   }

   
   // Step #3. Second DFS
   long long Answer = 0;

   for(int i=1; i<=N;i++){
       used[i]=false;
   }
   std::reverse(I.begin(),I.end());
   
   for(int i : I){
       cnt=0;
       if(used[i]==false){
           dfs2(i);
           Answer += cnt*(cnt -1LL)/2LL;
       }
   }

   // Step #4. Output The Answer!
   cout << Answer << endl;
   return 0;
}
*/
