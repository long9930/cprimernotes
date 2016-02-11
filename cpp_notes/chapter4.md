## C++ Primer C4.4



## C++ Primer C4.5 C4.6




## C++ Primer C4.7



## C++ Primer C4.9~C4.11

###The sizeof Operator
The ```sizeof``` operator returns the size, in bytes, of an expression or a type name. The operator is right associative. The result of sizeof is a constant expression of type ```size_t```. The operator takes one of two forms:

```cpp
sizeof (type)
sizeof expr
```

Examples

```cpp
Sales_data data, *p;
sizeof(Sales_data); // size required to hold an object of type Sales_data
sizeof data; // size of data's type, i.e., sizeof(Sales_data)
sizeof p;    // size of a pointer
sizeof *p;   // size of the type to which p points, i.e., sizeof(Sales_data)
sizeof data.revenue; // size of the type of Sales_data's revenue member
sizeof Sales_data::revenue; // alternative way to get the size of revenue
```

Under the new standard, we can use the scope operator to ask for the size of a member of a class type. 


The result of applying sizeof depends in part on the type involved:

* ```sizeof``` char or an expression of type char is guaranteed to be 1.
* ```sizeof``` a reference type returns the size of an object of the referenced type.
* ```sizeof``` a pointer returns the size needed hold a pointer.
* ```sizeof``` a dereferenced pointer returns the size of an object of the type to which the pointer points; the pointer need not be valid.
* ```sizeof``` an array is the size of the entire array. It is equivalent to taking the sizeof the element type times the number of elements in the array. Note that sizeof does not convert the array to a pointer.
* ```sizeof``` a string or a vector returns only the size of the fixed part of these types; it does not return the size used by the object’s elements.

```cpp
// sizeof(ia)/sizeof(*ia) returns the number of elements in ia
constexpr size_t sz = sizeof(ia)/sizeof(*ia);
int arr2[sz];  // ok sizeof returns a constant expression § 2.4.4 (p. 65)
```

### Comma Operator

The left-hand expression is evaluated and its result is discarded. The result of a comma expression is the value of its right-hand expression. The result is an lvalue if the right-hand operand is an lvalue.

```cpp
vector<int>::size_type cnt = ivec.size();
// assign values from size... 1 to the elements in ivec
for(vector<int>::size_type ix = 0;
                ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;
```


### Conversion

```cpp
int i, j;
double slope1 = i/j;
// cast used to force floating-point division
double slope2 = static_cast<double>(j) / i;
```


When we store a pointer in a ```void*``` and then use a ```static_cast``` to cast the pointer back to its original type, we are guaranteed that the pointer value is preserved. That is, the result of the cast will be equal to the original address value. However, we must be certain that the type to which we cast the pointer is the actual type of that pointer; if the types do not match, the result is undefined.

```cpp
double d;
void* p = &d;   // ok: address of any nonconst object can be stored in a void*
// ok: converts void* back to the original pointer type
double *dp = static_cast<double*>(p);
```

A ```const_cast``` changes only a low-level ```const``` in its operand:

```cpp
const char *pc;
char *p = const_cast<char*>(pc); // ok: but writing through p is undefined
```

Conventionally we say that a cast that converts a ```const``` object to a non```const``` type “casts away the const.” Once we have cast away the ```const``` of an object, the compiler will no longer prevent us from writing to that object. If the object was originally not a ```const```, using a cast to obtain write access is legal. However, using a const_cast in order to write to a ```const``` object is undefined.
Only a const_cast may be used to change the constness of an expression. Trying to change whether an expression is const with any of the other forms of named cast is a compile-time error. Similarly, we cannot use a const_cast to change the type of an expression:

```cpp
const char *cp;
// error: static_cast can't cast away const
char *q = static_cast<char*>(cp);
static_cast<string>(cp); // ok: converts string literal to string
const_cast<string>(cp);  // error: const_cast only changes constness
```

```cpp
int *ip;
char *pc = reinterpret_cast<char*>(ip);
string str(pc);
```

The last statement above is likely to result in bizarre run-time behavior.


#### Old style C cast

```cpp
type (expr); // function-style cast notation
(type) expr; // C-language-style cast notation
int i;  double d;  const string *ps;  char *pc;  void *pv;
char *pc = (char*) ip; // ip is a pointer to int
pv = (void*) ps;
i = int (*pc);
pv = &d;
pc = (char*) pv;
```