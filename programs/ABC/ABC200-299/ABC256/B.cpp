#include <iostream> 

using namespace std;

int main(){
int n;
  cin>>n;
  string s;
  for(int i=0;i<n;i++){
int a=0;cin>>a;
    s="1"+s;
    while(a-- >1)s="0"+s;
  }
  int p=0;
  for(int i=3;i<s.size();i++)if(s[i]=='1')p++;
  cout << p;
}