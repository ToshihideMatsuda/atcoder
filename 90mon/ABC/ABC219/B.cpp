#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<string> S;
	string T;
	
	string s;
    cin >> s;
    S.push_back(s);
    
    cin >> s;
    S.push_back(s);
    
    cin >> s;
    S.push_back(s);
    
    cin >> T;
    
    string ans="";
    
    for(int i=0;i<T.size();i++){
    	ans+=S[T[i]-'1'];
    }
    
    cout << ans;
    
    return 0;
}
