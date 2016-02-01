# Chapter 3, Strings, Vectors, Arrays
## 3.1 Namespaces
A ```using``` declaration lets us use a name from a namespace without qualifying the name with a ```namespace_name::``` prefix. A using declaration has the form

```cpp
using namespace::name;
```

Once the ```using``` declaration has been made, we can access name directly:

```cpp
#include <iostream>
// using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
int main()
{
    int i;
    cin >> i;       // ok: cin is a synonym for std::cin
    cout << i;      // error: no using declaration; we must use the full name
    std::cout << i; // ok: explicitly use cout from namepsace std
    return 0;
}
```

* A Separate ```using``` Declaration Is Required for Each Name
* Headers Should Not Include ```using``` Declarations

## 3.2 Library string Type


## 3.3 Library vector Type
