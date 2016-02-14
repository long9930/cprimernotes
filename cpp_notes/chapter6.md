### 6.7. Pointers to Functions XW ###

* A function pointer is a pointer that denotes a function rather than an object. 
* A function pointer points to a particular type, determined by its return type and the types of its parameters. 
* The function’s name is not part of its type. 
```cpp
// compares lengths of two strings
bool lengthCompare(const string &, const string &);
```
has type bool(const string&, const string&). To declare a pointer that can point at this function, we declare a pointer in place of the function name:
```cpp
// pf points to a function returning bool that takes two const string references
bool (*pf)(const string &, const string &);  // uninitialized
```
Starting from the name we are declaring, we see that pf is preceded by a *, so pf is a pointer. To the right is a parameter list, which means that pf points to a function. Looking left, we find that the type the function returns is bool. Thus, pf points to a function that has two const string& parameters and returns bool.

The parentheses around *pf are necessary. If we omit the parentheses, then we declare pf as a function that returns a pointer to bool:
```cpp
// declares a function named pf that returns a bool*
bool *pf(const string &, const string &);
```
