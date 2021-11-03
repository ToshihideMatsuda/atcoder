//
//  007.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
//Lower_bound による2分探索

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mydistance007(int a, int b);



int main007(){
    
    int n;
    int q;
    cin >> n;
    vector<int> a;
    vector<int>::iterator idxp;
    for(int i = 0 ; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> q;
    int b[q];
    for(int i = 0 ; i < q; i++){cin >>b[i]; }
    
    sort(a.begin(),a.end());
    
    
    for(int i = 0; i< q; i++) {
        idxp = std::lower_bound(a.begin(),a.end(), b[i]);
        int idx;
        idx = distance(a.begin(),idxp);
        
        int value = 0;
        
        if(idx == 0) {
            value = mydistance007(a[idx], b[i]);
        }
        else {
            int sup = a[idx];
            int inf = a[idx - 1];
            value = min(mydistance007(inf, b[i]),mydistance007(sup, b[i]));
        }
        
        std::cout << value << "\n";
    }

    return 0;
}


int mydistance007(int a, int b) {
    int abs = a-b;
    if(abs < 0) {
        return abs * -1;
    }
    return abs ;
}
/* 自分で2分探索
 
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int from, int to , int b);
int distance(int a, int b);
int a[300000];


int main007(){
    
    int n;
    int q;
    cin >> n;
    for(int i = 0 ; i < n; i++){cin >> a[i];}
    cin >> q;
    int b[q];
    for(int i = 0 ; i < q; i++){cin >>b[i]; }
    
    sort(a, a+n);
    
    for(int i = 0; i< q; i++) {
        int idx = binarySearch(0, n -1, b[i]);
        int value = 0;
        
        if(idx == 0) {
            value = distance(a[idx], b[i]);
        }
        else {
            int sup = a[idx];
            int inf = a[idx - 1];
            value = min(distance(inf, b[i]),distance(sup, b[i]));
        }
        
        std::cout << value << "\n";
    }

    return 0;
}


int binarySearch(int from, int to , int b){
    if(from == to){
        return from;
    }
    
    int idx = (to  + from) / 2 ;
    
    int v = a[idx];
    
    if(v == b){
        return idx;
    } else if (v < b) {
        return binarySearch(idx + 1, to, b);
    }
    else  { // v > b
        return binarySearch(from, idx, b);
    }
    
}

int distance(int a, int b) {
    int abs = a-b;
    if(abs < 0) {
        return abs * -1;
    }
    return abs ;
}

*/
