ll get10Keta(ll N) {
  ll k = 0;
  ll tmp = N; 
  while(tmp > 0) {
    tmp /= 10;
    k++;
  }
  return k;
}

ll getTen(ll N) {
  ll ten = 1; 
  while(N > 0) {
    ten *= 10;
    N--;
  }
  return ten;
}