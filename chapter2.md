# Chapter 2

## 2.1 Primitive Build-in Types
C++ defines primitive types including **arithmetic types** and **viod type**. Arithmetic types represent: characters, integers, boolean values and floating-point numbers. Void type has no associated values and mostly can be used in the return type for functions that do not return a value.
### 2.1.1 Arithmetic Types
Two categories:**integral types**(include character and boolean types) and **floating-point types**


| **Type**  | **Meaning**  | **Minimum Size** |
|:------------- |:---------------:| -------------:|
| bool    | boolean |         NA|
| char     | character       |           8 bits |
| wchar_t | wide character       |           16 bits|
|char16_t|Unicode character|16 bits|
|char32_t|Unicode character|32 bits|
|short|short integer|16 bits|
|int|integer|16 bits|
|long|long integer|32 bits|
|long long| long integer|64 bits|
|float| single-precision floating-point|6 significant digits|
|double|double-precision floating-point|10 significant digits|
|long double|extended-precision floaing-point|10 significant digits|

* Machine-Level Representation of the Build-in Types: bits(computer store data) >> byte(computer deal with memory, 8, $2^n$) >> word(basic unit of storage, 32or64)**??**

#### Signed and Unsigned Types
Intergral types may be **signed**(+-0) or **unsigned**(>=0)

* Signed: int, short, long, long long
* Unsigned: unsigned int, unsigned shot...
* <mark>char, signed char, unchar</mark>

### 2.1.2 Type Conversions
Type of an object defines data & operations. Among the operations is the ability to convert objects of the given type to other types.

```cpp
bool b=42;// b is ture
int i=b;//i has the value 1
i=3.14;//i has the value 3
double pi=i;//pi has the value 3.0
unsigned char c=-1;//assuming 8-bit chars, c has value 255,the reslut is the remainder of the value modulo the number of values the target type can hold(unsigned)
signed char c2=256;//assuming 8-bit chars, the value of c2 is not defined.(result is undefined, signed)
```
The compiler applies these same type comversions when we use a value of one arithmetic type where a value of another arithmetic type is expected. When use none bool value as condition, the arithmetic value is convertde to bool. <mark> For example</mark>

```cpp
int i=42;
if (i)//condition will evaluate as ture
i=0;
```

#### Expressions Involoving Unsigned Types
Conversions happen when use both unsigned and int values in an arithmetic expression.

* when using unsigned types in an arithmetic expression, the result can not be negative.
* when using unsigned types in a loop, the loop may never terminate.

### 2.1.3 Literals
Every literal has a type. The form and value of a literal determine its type.
#### Integer and Floaing-Point Literals


* Integer literal can be written using demical,octal and hexadecimal notation.
* By default, demical literals are signed and have the<mark> samllest type of int, long or long long</mark> whereas octal and hexadecimal literals can be either signed or unsigned types and have the smallest type of (unsigned)int, (unsigned)long, (unsigned long long).
* There are no literals of type short.
* Floating-point literals include either a decimal point er an exponent specified using scientific notation.

```cpp
3.14159
3.14159E0
0.
0e0
.001
```

#### Charater and Character String Literals

* A character enclosed with single quotes is a literal of type char
* Zero or more characters enclosed in double quotation marks is a string literal; The type of a string literal is array of constant char's. **The actual size of a string literal is one more than its apparent size**


#### Esacpe Sequences
Characters have special meanings in the laguage.

|meaning| characters|meaning|characters|
|:---|:------:|:-----:|:-----:|
|newline|\n|horizontal tab|\t|
|alert(bell)|\a|vertial tab|\v|
|backspace|\b|double quote|\ "|
|backslash| \\\\|question mark|\?|
|single quote|\\|carriage returen|\t|
|formfeed|\f|

* If \ is followed by more than 3 octal digits, only the first 3 are assoiated with the \.*For example, \1234 represents two characters: the character represented by \123 and character 4*; in contrast,\x uses up all the hex digits following it.*For example,\x1234* is one character.


## 2.2

## 2.3 Compound Type
### 2.3.1 References
**Reference** type defines an alternative name for an object.
Once it's bound to an object, it could not be rebound to another object.

```cpp
int ival = 1024;
int &refVal = ival;
int &refVal2; // error: must be initialized.
int &refVal3 = 2048; //error: must be bound to an object.
```

### 2.3.2 Pointers
A **pointer** holds the address of another object. The reference variable does not have an address.


```cpp
int ival = 1024;
int *p = &ival;
*p = 2; //* yields the object; we assign value to ival
```

```cpp
int *p1 = nullptr;
int *p2 = 0;
int *p3 = NULL; // must #include cstdlib
```

*NULL* is a preprocessor variable, which is contained in the header *cstdlib*. Modern C++ programs should avoid using *NULL* and use *nullptr* instead.

```cpp
int i = 42;
int *pi = 0;   // pi is initialized but addresses no object
int *pi2 = &i; // pi2 initialized to hold the address of i
int *pi3;      // if pi3 is defined inside a block, pi3 is uninitialized
pi3 = pi2;        // pi3 and pi2 address the same object, e.g., i
pi =  &i;
*pi = 0;          // equivalent to i=0;
pi2 = 0;          // pi2 now addresses no object
```

Other pointer operation

1. Use in condition.

```cpp
int ival = 1024;
int *pi = 0;      // pi is a valid, null pointer
int *pi2 = &ival; // pi2 is a valid pointer that holds the address of ival
if (pi)  // pi has value 0, so condition evaluates as false
    // ...
if (pi2) // pi2 points to ival, so it is not 0; the condition evaluates as true
    // ...
```

2. Using equality(==) and inequality(!=). Two pointers hold the same address (i.e., are equal) if they are both null, if they address the same object, or if they are both pointers one past the same object.  

```cpp
int ival = 1024;
int *pi = 0;      // pi is a valid, null pointer
int *pi2 = &ival; // pi2 is a valid pointer that holds the address of ival
if (pi)  // pi has value 0, so condition evaluates as false
    // ...
if (pi2) // pi2 points to ival, so it is not 0; the condition evaluates as true
    // ...
```

The ```void``` type hold pointers to any type, but we could not use it to operate on the object it points to. Only use it to deal with memory.

```cpp
double obj = 3.14, *pd = &obj;
// ok: void* can hold the address value of any data pointer type
void *pv = &obj;  // obj can be an object of any type
pv = pd;          // pv can hold a pointer to any type
```

### Understanding Compound Type

As we’ve seen, a variable definition consists of a base type and a list of declarators. Each declarator can relate its variable to the base type differently from the other declarators in the same definition. Thus, a single definition might define variables of different types:

> Base Declarator


```cpp
// i is an int; p is a pointer to int; r is a reference to int
int i = 1024, *p = &i, &r = i;

int* p1, p2; // p1 is a pointer to int; p2 is an int

int *p1, *p2; // both p1 and p2 are pointers to int
```

Pointer to pointer. It must be dereferenced twice.

```cpp
int ival = 1024;
int *pi = &ival;    // pi points to an int
int **ppi = &pi;    // ppi points to a pointer to an int
cout << "The value of ival\n"
     << "direct value: " << ival << "\n"
     << "indirect value: " << *pi << "\n"
     << "doubly indirect value: " << **ppi
     << endl;
```

A reference is not an object. Hence, we may not have a pointer to a reference. However, because a pointer is an object, we can define a reference to a pointer:

```cpp
int i = 42;
int *p;        // p is a pointer to int
int *&r = p;   // r is a reference to the pointer p
r = &i; //  r refers to a pointer; assigning &i to r makes p point to i
*r = 0; //  dereferencing r yields i, the object to which p points; changes i to 0
```

## 2.4

```cpp
int x;
```