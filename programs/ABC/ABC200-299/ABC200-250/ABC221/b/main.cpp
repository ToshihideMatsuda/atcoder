#include <iostream>
#include <cmath>

using namespace std;
int main(){
	string s,t;
	cin >> s>>t;
	if(equal(s.begin(),s.end(),t.begin(),t.end()))
	{
		cout << "Yes" << endl;
		return 0;
	}
	
	for( int i=0;i<s.size()-1;i++){
		swap(s[i],s[i+1]);
		if(equal(s.begin(),s.end(),t.begin(),t.end()))
		{
			cout << "Yes" << endl;
			return 0;
		}
		swap(s[i],s[i+1]);
	}
	
	cout << "No" << endl;
	
	
	
	return 0;
}
