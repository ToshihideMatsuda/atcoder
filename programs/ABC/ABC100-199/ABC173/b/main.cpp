#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 

typedef long long ll;
#define MOD 998244353

	
int main(){
	ll N;cin>>N;
	ll ac=0,wa=0,tle=0,re=0;
	rep(i,N){
		string s;cin>>s;
		if(s=="AC")ac++;
		else if(s=="WA")wa++;
		else if(s=="TLE")tle++;
		else re++;
	}
	cout<<"AC x "<<ac<<endl;
	cout<<"WA x "<<wa<<endl;
	cout<<"TLE x "<<tle<<endl;
	cout<<"RE x "<<re<<endl;
	
    return 0;
}
