## 6.4. Overloaded Functions ##
**Definition**: Functions that have the same name but different parameter lists and that appear in the sam e scope are **overloaded**.

~~~cpp
void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size-t size);

int j[2] = {0,1};
print("Hello World");        // calls print(const char*)
print(j, end(j) - begin(j)); // calls print(const int*, size_t)
print(begin(j), end(j));     // calls print(const int*, const int*)

~~~

These functions perform the same general action but apply to different parameter types. When we call these functions, the compiler can deduce which funciton we want based on the argument type we pass.

**Advantages**: eliminate the need to invent and remember names that exist only to help the compiler gigure out which function to call.

we should only overload operations that actually do similar things.

###Define Overloaded Functions###
Overloaded functions must differ in the **number** or the **types** of their parameters.

**Return types** is **not** considered as a difference!!!

~~~cpp
Record lookup(const Account&);  // find by Account
Record lookup(const Phone&);    // find by Phone
Record lookup(const Name&);     // find by Name

Account acct;
Phone phone;
Record r1 = lookup(acct);  // call version that takes an Account
Record r2 = lookup(phone); // call version that takes a Phone

bool lookup(const Account&);   // error: only the return type is different
~~~

###Determining Whether Two Parameter Types Differ###
Two parameter lists can be identical, even if they don't look the same:

~~~cpp
// each pair declares the same function
Record lookup(const Account &acct);
Record lookup(const Account&); // parameter names are ignored

typedef Phone Telno;
Record lookup(const Phone&);
Record lookup(const Telno&); // Telno and Phone are the same type
~~~

###Top-level `cosnt` and low-level `const` in overloaded functions###
We use the term **top-level const** to indicate that the pointer or variable itself is a const. When a pointer can point to a const object, we refer to that const as a **low-level const**.

~~~cpp
int i = 0;
int *const p1 = &i;  // we can't change the value of p1; const is top-level
const int ci = 42;   // we cannot change ci; const is top-level
const int *p2 = &ci; // we can change p2; const is low-level
const int *const p3 = p2; // right-most const is top-level, left-most is not
const int &r = ci;  // const in reference types is always low-level
~~~

A parameter that has a top-level const is indistinguishable from one without a top-level const, because the top-level const attribute is not passed when variable is copied.

~~~cpp
Record lookup(Phone);
Record lookup(const Phone);   // redeclares Record lookup(Phone)

Record lookup(Phone*);
Record lookup(Phone* const);  // redeclares Record lookup(Phone*)
~~~

Low-level const can be distinguished:

~~~cpp
Record lookup(Account&);       // function that takes a reference to Account
Record lookup(const Account&); // new function that takes a const reference

Record lookup(Account*);       // new function, takes a pointer to Account
Record lookup(const Account*); // new function, takes a pointer to const
~~~
###Calling an Overloaded Function###
**Function matching** (also known as overload resolution) is the process by which a particular function call is associated with a specific function from a set of overloaded functions. The compiler determines which function to call by comparing the arguments in the call with the parameters offered by each function in the overload set.

**Possible Outcomes**:

* The compiler finds exactly ***one function*** that is a best match for the actual arguments and generates code to call that function.
* There is ***no function*** with parameters that match the arguments in the call, in which case the compiler issues an error message that there was no match.
* There is ***more than one function*** that matches and none of the matches is clearly best. This case is also an error; it is an ambiguous call.

###Overloading and Scope###
If we declare a name in an inner scope, that name hides uses of that name declared in an outer scope. Names do not overload across scopes:

~~~cpp
string read();
void print(const string &);
void print(double);   // overloads the print function
void fooBar(int ival)
{
    bool read = false; // new scope: hides the outer declaration of read
    string s = read(); // error: read is a bool variable, not a function
    // bad practice: usually it's a bad idea to declare functions at local scope
    void print(int);  // new scope: hides previous instances of print
    print("Value: "); // error: print(const string &) is hidden
    print(ival);      // ok: print(int) is visible
    print(3.14);      // ok: calls print(int); print(double) is hidden
}
~~~


## 6.7. Pointers to Functions XW ##

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


###Function Pointer Parameters###
* we can have a parameter that is a pointer to function. 
* we can write a parameter that looks like a function type, but it will be treated as a pointer
```cpp
// third parameter is a function type and is automatically treated as a pointer to function
void useBigger(const string &s1, const string &s2,
               bool pf(const string &, const string &));
// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2,
               bool (*pf)(const string &, const string &));
```
* When we pass a function as an argument, we can do so directly. It will be automatically converted to a pointer:
```cpp
// automatically converts the function lengthCompare to a pointer to function
useBigger(s1, s2, lengthCompare);
```
* Type aliases and decltype can simplify code that uses function pointers:
```cpp
// Func and Func2 have function type
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2; // equivalent type

// FuncP and FuncP2 have pointer to function type
typedef bool(*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2;  // equivalent type
```

Here we’ve used typedef to define our types. Both Func and Func2 are function types, whereas FuncP and FuncP2 are pointer types. 
* decltype returns the function type; 
* the automatic conversion to pointer is not done. 
* if we want a pointer we must add the * ourselves. 
```cpp
// equivalent declarations of useBigger using type aliases
void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP2);
```
* Both declarations declare the same function.
* In the first case, the compiler will automatically convert the function type represented by Func to a pointer.


###Returning a Pointer to Function###
* we can’t return a function type but can return a pointer to a function type. 
* we must write the return type as a pointer type; 
* the compiler will not automatically treat a function return type as the corresponding pointer type. 
* the easiest way to declare a function that returns a pointer to function is by using a type alias:
```cpp
using F = int(int*, int);     // F is a function type, not a pointer
using PF = int(*)(int*, int); // PF is a pointer type
```
Here we used type alias declarations to define F as a function type and PF as a pointer to function type. 
* the return type is not automatically converted to a pointer type. 
* We must explicitly specify that the return type is a pointer type:
```cpp
PF f1(int); // ok: PF is a pointer to function; f1 returns a pointer to function
F f1(int);  // error: F is a function type; f1 can't return a function
F *f1(int); // ok: explicitly specify that the return type is a pointer to function
```

Of course, we can also declare f1 directly, which we’d do as
```cpp
int (*f1(int))(int*, int);
```

* Reading this declaration from the inside out
* f1 has a parameter list, so f1 is a function. 
* f1 is preceded by a * so f1 returns a pointer. 
* The type of that pointer itself has a parameter list, so the pointer points to a function. 
* That function returns an int.


* we can simplify declarations of functions that return pointers to function by using a ```trailing return```:
```cpp
auto f1(int) -> int (*)(int*, int);
```

###Using auto or decltype for Function Pointer Types###
* If we know which function(s) we want to return, we can use decltype to simplify writing a function pointer return type. 
* assume we have two functions, both of which return a string::size_type and have two const string& parameters. 
* We can write a third function that takes a string parameter and returns a pointer to one of these two functions as follows:
```cpp
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength
decltype(sumLength) *getFcn(const string &);
```

* when we apply decltype to a function, it returns a function type, not a pointer to function type. 
* We must add a * to indicate that we are returning a pointer, not a function.
