#include <iostream>
#include <vector>

#define MAX_N 200009

using namespace std;

int N,M;
vector<int> G[MAX_N];
int used[MAX_N];

int vcnt;
int ecnt;
void dfs(int v){
	used[v]=true;
	vcnt++;
	ecnt+=G[v].size();
	for(auto u : G[v]){
		if(used[u]==false) {
			dfs(u);
		}
	}
} 

int main(){
	cin >> N >>M;
	
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int cnt=0;
	for(int i=1;i<=N;i++){
		if(used[i]==false) {
			ecnt=0;
			vcnt=0;
			dfs(i);
			
			
			if(vcnt<=2||2*vcnt!=ecnt){
				cout << 0;
				return 0;
			}
			cnt++;
		}
	}
	
	int ans=1;
	while(cnt-->0){
		ans*=2;
		ans%=998244353;
	}
	
	cout << ans;
	
	return 0;
}

