#include <iostream>

using namespace std;
int main(){
	int n,m;
	cin >> n;
	
	m=1;
	while(true){
	if(m*(m+1)/2>=n){

		break;
		}
				m++;
	}
	
	
	
	
	cout<<m;
	
	return 0;
}
