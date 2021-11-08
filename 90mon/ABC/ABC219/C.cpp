#include <iostream>
#include <vector>
#include <limits>

using namespace std;

char order[26];

int main(){
	string X;
	int N;
    cin >> X >> N;
    
    vector<string>S;
    
    for(int i=0;i<N;i++){
    	string s;
    	cin >> s;
    	S.push_back(s);
    }
    
    
    
    for(int i=0;i<26;i++){
    	order[X[i]-'a']=i;
    }
    
    auto orderfunc = [](string a, string b) { 
    	for(int i=0;i<min(a.size(),b.size());i++){
    		if(a[i] != b[i]) 
    		return order[a[i]-'a'] < order[b[i]-'a'] ;
    	}
    	
    	return a.size() < b.size();
    };
    
    
    sort(S.begin(), S.end(), orderfunc); 
    
    for(auto s:S)
    cout << s << endl;
    
    return 0;
}
