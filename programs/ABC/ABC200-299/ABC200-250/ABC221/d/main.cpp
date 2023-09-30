#include <iostream>
#include <cmath>
#include <map>

int sum[2*100000+9];

using namespace std;
int main(){
	int n,a,b;
	cin >> n;
	
	map<int,int> ab;
	
	for(int i=0;i<n;i++){
		cin >> a >>b;
		ab[a]+=1;
		ab[a+b]-=1;
	}
	
	int cur=0;
	pair<int,int> prev={0,0};
	
	for(auto event:ab){
		
		
		/*cout <<"event:{"<<event.first<<","<<event.second<<"}"<<endl;*/
		
		
		
		if(event.second==0){
			continue;
		}
		else if(prev.first==0){
			prev=event;
			cur+=event.second;
			continue;
		}
		else{
		
		
		sum[cur]+=event.first-prev.first;
		prev=event;
		cur+=event.second;
		}
		/*
		
		for(int i=1;i<n+1;i++)cout << sum[i] <<" ";
		cout << endl;*/
		
	}	
	
	sum[cur]+=n-prev.first+1;
	
	
	for(int i=1;i<n+1;i++){
		cout << sum[i] <<" ";
	}
	cout <<endl;
	
	return 0;
}
