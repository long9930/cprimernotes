#include <iostream>

using namespace std;

int main() {
  int i;
  for (i=0; i<100; i++) {
    if (i == 50) {
      break;
    }
  }

  cout << "For loop ended!" << endl;
  cout << "i = " << i << endl;
}

