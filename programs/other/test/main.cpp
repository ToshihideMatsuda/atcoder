#include <iostream>
#define v void
int z = 1;
v a(){std::cout << "Hello, World!" << z++ << "\n" ; } 
v b(){a();a();} // 2^1
v c(){b();b();} // 2^2
v d(){c();c();} // 2^3
v e(){d();d();} // 2^4
v f(){e();e();} // 2^5
v g(){f();f();} // 2^6
v h(){g();g();} // 2^7
v i(){h();h();} // 2^8
v j(){i();i();} // 2^9
v k(){j();j();} // 2^10
v l(){k();k();} // 2^11
v m(){l();l();} // 2^12
v n(){m();m();} // 2^13
v o(){n();n();} // 2^14
v p(){o();o();} // 2^15
v q(){p();p();} // 2^16
v r(){q();q();} // 2^17
v s(){r();r();} // 2^18
v t(){s();s();} // 2^19
//tsrqponmlkjihgfedcba
//11110100001001000000
int main() { t();s();r();q();o();j();g(); return 0; } 