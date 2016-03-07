#include <iostream>

using namespace std;

int add(int a, int b) {
  int c = a + b;
  return c; // Return back to where the function is called
}

int main() {
  int a = 0;
  int b = 1;
  int c;
  while (c < 100) {
    c = add(a, b);
    a = b;
    b = c;
    cout << c << endl;
  }
  return 0;
}

