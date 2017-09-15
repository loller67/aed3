#include "Exacto.h"



int main(){
  int n, m;
  cin >> n;
  cin >> m;
  AdyMatrix M(n);
  getInputEj1(M,n,m);

  Solucion sol = Ej1(M,n,m);
  std::cout << sol << '\n';
  return 0;
}
