#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
int c[10000000+9];
void elatsWithFactor(int N){
	for(int i= 2; i<N+1;i++){
		c[i]=0;
	}
	
	for(int i= 2; i<N+1;i++){
		if(c[i]==0){
			for(int j=i;j<N+1;j +=i){
				c[j] +=1;
			}
		}
	}
}

int main() {
	
	int N,K;
	
	cin >> N >> K;
	
	elatsWithFactor(N);
	
	int cnt =0;
	
	for(int i= 2; i<N+1;i++){
		if(c[i]>=K) cnt++;
	}
	
	cout << cnt;
	
	
	return 0;
}
