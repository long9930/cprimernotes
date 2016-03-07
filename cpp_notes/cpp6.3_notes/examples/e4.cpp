#include <iostream>
using namespace std;
string fun_hello() {
  while (false) {
    return "A string";
  }
}
int main() {
  cout << fun_hello() << endl;
}




