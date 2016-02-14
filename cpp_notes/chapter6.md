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



###Using Function Pointers###
* When we use the name of a function as a value, the function is automatically converted to a pointer. 
```cpp
pf = lengthCompare;  // pf now points to the function named lengthCompare
pf = &lengthCompare; // equivalent assignment: address-of operator is optional
```
* we can use a pointer to a function to call the function to which the pointer points. 
* there is no need to dereference the pointer:
```cpp
bool b1 = pf("hello", "goodbye");    // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye"); // equivalent call
bool b3 = lengthCompare("hello", "goodbye"); // equivalent call
```
* There is no conversion between pointers to one function type and pointers to another function type. 
* we can assign nullptr or a zero-valued integer constant expression to a function pointer to indicate that the pointer does not point to any function:
```cpp
string::size_type sumLength(const string&, const string&);
bool cstringCompare(const char*, const char*);
pf = 0;              // ok: pf points to no function
pf = sumLength;      // error: return type differs
pf = cstringCompare; // error: parameter types differ
pf = lengthCompare;  // ok: function and pointer types match exactly
```

###Pointers to Overloaded Functions###
* When we declare a pointer to an overloaded function, the compiler uses the type of the pointer to determine which overloaded function to use. 
```cpp
void ff(int*);
void ff(unsigned int);
void (*pf1)(unsigned int) = ff;  // pf1 points to ff(unsigned)
```
* The type of the pointer must match one of the overloaded functions exactly:
```cpp
void (*pf2)(int) = ff;    // error: no ff with a matching parameter list
double (*pf3)(int*) = ff; // error: return type of ff and pf3 don't match
```
