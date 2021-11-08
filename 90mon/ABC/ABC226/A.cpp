#include <iostream>

using namespace std;

#define max 300 + 1
int main() {

    string X;
    cin >> X;

    int last = X.find_first_of('.');
    
    std::string d(X, 0  ,last);
    std::string a(X, last+1, 1);
    if('0' <= a[0] && a[0]<='4')
        cout << d;
    else {
        int dd = stoi(d);
        cout << (dd+1);
    }


    return 0;
}