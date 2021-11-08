#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define max 300 + 1
int main() {
    int N;
    cin >> N;

    set<vector<int>> set; 

    for (int i = 0; i < N; i++)
    {
        int L;
        cin >> L;
    
        vector<int> setin; 
        for(int j = 0; j < L; j++) {
            int a;
            cin >> a;
            setin.push_back(a);
        }
        set.insert(setin);
    }
    
    cout << set.size();


    return 0;
}