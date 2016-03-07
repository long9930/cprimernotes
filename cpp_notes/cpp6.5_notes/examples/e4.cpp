#define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;
int main() {
  int i = 10;
  assert(i<5);
}
// output:
// e4.cpp:6:7: warning: unused variable 'i' [-Wunused-variable]
//   int i = 10;
//       ^
// 1 warning generated.



