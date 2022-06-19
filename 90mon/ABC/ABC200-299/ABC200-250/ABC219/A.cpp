#include <iostream>

using namespace std;

int main(){
	int X;
    cin >> X;
    if(0<=X&&X<40) cout << 40-X;
    else if(40<=X&&X<70) cout << 70-X;
    else if(70<=X&&X<90) cout << 90-X;
    else cout << "expert";
    
    return 0;
}
