
#include <iostream>
using namespace std;
int * fun_hello() {
  static int a[10];
  for (int i=0; i<10; i++)
    a[i] = i*i;
  return a;
}
int main() {
  int * p;
  p = fun_hello();
  for ( int i = 0; i < 10; i++ )
    cout << p[i] << endl;
}




