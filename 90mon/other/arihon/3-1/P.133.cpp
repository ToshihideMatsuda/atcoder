#include <iostream>
#include <vector>
#include <set>
#include <map>


#define MAX_N 200009

using namespace std;


int n =3;
int k =2;
vector<pair<int,int>> wvs = {{2,2},{5,3},{2,1}};

bool C(double x) {

    vector<double> y;

    for(int i = 0; i < n; i ++) {
        y.push_back(wvs[i].second -  wvs[i].first * x);
    }

    sort(y.begin(),y.end(),greater<double>());

    double sum = 0;
    for(int i = 0; i < k; i ++) {
        sum += y[i];
    }

    return sum >= 0;
}


int main(){
    
    double min = 0;
    double max = (double)(1 << 28);

    for(int i = 0; i < 10000; i ++) {
        double mid = (min + max) /2;
        if(C(mid)) 
            min = mid;
        else 
            max = mid;
    }

    cout << (min + max)/2 << endl;



    return 0;
}
