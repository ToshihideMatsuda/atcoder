#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
long long A[2*100000+9];

int main(){
	string A,B;
	cin >> A>>B;
	string ans  ="Easy";
	string a (A.rbegin(), A.rend());
	string b (B.rbegin(), B.rend());

	for(int i=0;i<min(a.length(),b.length());i++){
		int sum= (a[i]-'0')+(b[i]-'0');
		if(sum>=10){
			
		ans="Hard";
			}
	}
	
	cout<< ans;
    
    return 0;
}
