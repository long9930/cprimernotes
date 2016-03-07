#include <iostream>
using namespace std;
inline string fun_hello(int &i) {
  return i > 0? "hello" : "world";
}
int main() {
  int i = 3, j = -3;
  cout << fun_hello(i) << endl;
  cout << fun_hello(j) << endl;
}




