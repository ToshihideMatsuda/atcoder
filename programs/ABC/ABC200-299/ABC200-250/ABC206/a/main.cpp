#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	
	int m=(int)(1.08*n);
	if(m<206)cout <<"Yay!";
	else if(m==206) cout<<"so-so";
	else cout << ":(";
	
	
	return 0;
}
