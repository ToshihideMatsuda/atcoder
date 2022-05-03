#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
long long A[2*100000+9];

int main(){
	string s1,s2;
	cin >> s1>>s2;
	string ans="Yes";
	if((s1==".#"&&s2=="#.")||(s1=="#."&&s2==".#"))ans="No";
	
	cout<< ans;
    
    return 0;
}
