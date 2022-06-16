#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
long long A[2*100000+9];

int main(){
	int A,B,C;
    cin >> A >> B >> C;
    int min=((A+(C-1))/C)*C;

    if(min > B) cout << -1;
    else cout << min;
    
    return 0;
}