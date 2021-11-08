#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int X[500 + 1],Y[500 + 1];
typedef long long ll;

//aとbの最大公約数を計算
int absgcd(int a, int b) {
    if(a < 0) a = -a;
    if(b < 0) b = -b;

    if(b == 0) return a;
    return absgcd(b, a%b);
}

int main() {
    cin >> N;

    for (int i = 1; i < N+1; i++)
    {
        cin >> X[i] >> Y[i];
    }


    set<pair<int,int>> s;

    for (int i = 1; i < N+1; i++)
    {
        for (int j = 1; j < N+1; j++)
        {
            if(i == j) continue;

            int dX = X[i] - X[j];
            int dY = Y[i] - Y[j];
            int g = absgcd(dX,dY);
            s.insert({dX/g, dY/g});
        }
    }

    cout << s.size();

    return 0;
}