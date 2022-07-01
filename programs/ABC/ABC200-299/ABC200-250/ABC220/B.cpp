#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
long long A[2*100000+9];

long long toInt(string A,int K){
	long long iA=0;
	int mul=1;
    for(int i =A.size()-1;i>-1;i--){
    	iA+=(A[i] - '0')*mul;
    	mul*=K;
    }
    return iA;
 }


int main(){
	int K;
	string A,B;
    cin >> K >> A >> B;
    
    long long iA=toInt(A,K);
    long long iB=toInt(B,K);
    
    
    cout<<iA*iB<<endl;
    
    return 0;
}