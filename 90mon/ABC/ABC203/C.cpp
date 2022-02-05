#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
map<ll,ll> m;
int main(){
	int n,k;
	cin >> n>>k;
	
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin >> a >> b;
		m[a]+=b;
	}
	
	
	ll pos    =0;
	ll money  =k;
	
	for(auto itr =m.begin();itr !=m.end();++itr){
		if(itr->first <= money+pos){
			money = money - (itr->first) +(itr->second);
			pos += itr->first;
		}
		else{
			pos +=money;
			money=0;
			break;
		}
	}
	pos +=money;
		
	cout <<pos <<endl;
	
	return 0;
}
