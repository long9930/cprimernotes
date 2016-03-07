#include <iostream>
using namespace std;
void fun_hello(int &i) {
  i = i * 3;
  return;
}
int main() {
  int i = 3;
  fun_hello(i);
  cout << i << endl;
}




