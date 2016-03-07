#include <iostream>
using namespace std;
class a_long_and_complicated_class_name {
public:
  typedef string id;
  int get_var1();
  double get_var2();
  id get_id();
private:
  int var1 = 42;
  double var2 = 3.14159265359;
  id var3 = "This makes a difference"; 
};
auto a_long_and_complicated_class_name::get_var1() -> int {
  return var1;
}
auto a_long_and_complicated_class_name::get_var2() -> double {
  return var2;
}
auto a_long_and_complicated_class_name::get_id() -> id {
  return var3;
}
int main() {
  a_long_and_complicated_class_name ac;
  cout << ac.get_var1() << endl;
  cout << ac.get_var2() << endl;
  cout << ac.get_id() << endl;
}




