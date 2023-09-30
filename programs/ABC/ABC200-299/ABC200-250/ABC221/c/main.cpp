#include <iostream>
#include <cmath>
#include <vector>


using namespace std;
int main(){
	string n;
	cin >> n;
	int ni=stoi(n);
	
	int patarn=pow(2,n.size());
	int max=0;
	for(int p=1;p<patarn-1;p++){
		int tmp=p;
		//cout << "p:" <<p <<endl;
		vector<int> v1,v2;
		
		int itr=0;
		while(itr < n.size()){
			if(tmp&1==1){
				v1.push_back(n[itr]-'0');
			}
			else{
				v2.push_back(n[itr]-'0');
			}
			tmp=tmp>>1;
			itr++;
		}
		
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		/*
		cout << "v1:";
		for(int i=0;i<v1.size();i++){
			cout << v1[i] << " ";
		}
		cout << endl;
		cout << "v2:";
		for(int i=0;i<v2.size();i++){
			cout << v2[i] << " ";
		}
		cout << endl;
		*/
		
		int vl1=0,vl2=0;
		
		for(int i=0;i<v1.size();i++){
			vl1=v1[i]*pow(10,i)+vl1;
		}
		for(int i=0;i<v2.size();i++){
			vl2=v2[i]*pow(10,i)+vl2;
		}
		
		if(vl1>0&&vl2>0){
			int val =vl1*vl2;
			max=max<val?val:max;
		}
	}
	
	cout <<max <<endl;
	
	
	
	
	
	return 0;
}
