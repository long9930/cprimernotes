#include <iostream>

using namespace std;

int main() {
  int i, j, k;
  k = 0;

 place_to_loop:
  for (i=k; i<100; i++) {
    if (i==10) {
      goto place_to_double;
    }
    k = i * i;
    j = i + k;
  }
  
 place_to_square:
  i = i * i;
  goto place_to_loop;
  
 place_to_switch:
  i = j;
  j = k;
  k = i;

 place_to_double:
  i = i + i;
  if (j > k) {
    goto place_to_switch;
  } else if (j == k) {
    goto place_to_square;
  } else {
    k = i + j;
  }
  
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "k = " << j << endl;
  return 0;
}

