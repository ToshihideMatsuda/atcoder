#include <iostream>
#include <cmath>

using namespace std;
int main(){
	int a,b;
	cin >> a >>b;
	
	long long m=1;
	while(a-b>0){
		m*=32;
		a--;
	}
	cout <<m<<endl;
	
	
	
	return 0;
}
