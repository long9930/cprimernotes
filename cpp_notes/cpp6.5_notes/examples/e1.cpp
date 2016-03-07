#include <iostream>
using namespace std;
string fun_hello(string s="HELLO") {
  return s;
}
int main() {
  cout << fun_hello() << endl;
  cout << fun_hello("WORLD") << endl;
}




