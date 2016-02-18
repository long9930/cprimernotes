#include <iostream>

using namespace std;

int main() {
  int i, j, counter=0;
  for (j=0; j<10; j++) {
    for (i=0; i<100; i++) {
      if (i == 50) {
	break;
      }
      counter++;
    }
  }

  cout << "For loops ended!" << endl;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "counter = " << counter << endl;
}

