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


## 2.2. Variables
A variable provides us with named storage that our programs can manipulate.
###2.2.1. Variable Definitions
A simple variable definition consists of a <mark>type specifier</mark>, followed by a list of one or more variable names separated by commas, and ends with a semicolon. Each name in the list has the type defined by the type specifier. A definition may (optionally) provide an initial value for one or more of the names it defines:

```cpp
int sum = 0, value, // sum, value, and units_sold have type int 
    units_sold = 0; // sum and units_sold have initial value 0
Sales_item item; // item has type Sales_item (see § 1.5.1 (p. 20))
// string is a library type, representing a variable-length sequence of characters 
std::string book("0-201-78345-X"); // book initialized from string literal
```
* The definition of book uses the std::string library type.

####Initializers
An object that is initialized gets the specified value at the moment it is created. The values used to initialize a variable can be arbitrarily complicated expressions. When a definition defines two or more variables, the name of each object becomes visible immediately. Thus, it is possible to initialize a variable to the value of one defined earlier in the same definition.

```cpp
// ok: price is defined and initialized before it is used to initialize discount 
double price = 109.99, discount = price * 0.16;
// ok: call applyDiscount and use the return value to initialize salePrice
double salePrice = applyDiscount(price, discount);
```
*Initialization is not assignment. Initialization happens when a variable is given a value when it is created. Assignment obliterates an object’s current value and replaces that value with a new one.
 
####List Initialization
We can use any of the following four different ways to define an int variable named units_sold and initialize it to 0:

```cpp
int units_sold = 0; 
int units_sold = {0}; 
int units_sold{0}; 
int units_sold(0);
```
* For reasons we’ll learn about in § 3.3.1 (p. 98), this form of initialization is referred to as <mark>list initialization</mark>. 

When used with variables of built-in type, this form of initialization has one important property: The compiler will not let us list initialize variables of built-in type if the initializer might lead to the loss of information:

```cpp
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required 
int c(ld), d = ld; // ok: but value will be truncated
```

The compiler rejects the initializations of a and b because using a long double to initialize an int is likely to lose data. At a minimum, the fractional part of ld will be truncated. In addition, the integer part in ld might be too large to fit in an int.

####Default Initialization
When we define a variable without an initializer, the variable is <mark>default initialized</mark>.

The value of an object of built-in type that is not explicitly initialized depends on where it is defined.Variables defined outside any function body are initialized to zero. With one exception, which we cover in § 6.1.1 (p. 205), variables of built-in type defined inside a function are uninitialized. The value of an uninitialized variable of built-in type is undefined (§ 2.1.2, p. 36).

Most classes let us define objects without explicit initializers. Such classes supply an appropriate default value for us. Some classes require that every object be explicitly initialized. The compiler will complain if we try to create an object of such a class with no initializer.

```cpp
std::string empty; // empty implicitly initialized to the empty string
Sales_item item; // default-initialized Sales_item object
```
###2.2.2. Variable Declarations and Definitions
We recommend initializing every object of built-in type. It is not always necessary, but it is easier and safer to provide an initializer until you can be certain it is safe to omit the initializer.
 
 A <mark>declaration</mark> makes a name known to the program. A variable declaration specifies the type and name of a variable. A variable definition is a declaration. In addition to specifying the name and type, a definition also allocates storage and may provide the variable with an initial value. An extern that has an initializer is a <mark>definition</mark>.

```cpp
extern int i; // declares but does not define i 
int j; // declares and defines j
extern double pi = 3.1416; // definition
```
* It is an error to provide an initializer on an extern inside a function.
* To use a variable in more than one file requires declarations that are separate from the variable’s definition. To use the same variable in multiple files, we must define that variable in one—and only one—file. Other files that use that variable must declare—but not define—that variable.

####2.2.3. Identifiers
The language imposes no limit on name length. <mark>Identifiers</mark> must begin with either a letter or an underscore. Identifiers are case-sensitive.

C++ Keywords and C++ Alternative Operator Names (refer to the book) cannot be used as identifiers.

Conventions:

* Variable names normally are lowercase—index, not Index or INDEX.
*  Like Sales_item, classes we define usually begin with an uppercase letter.

####2.2.4. Scope of a Name
A <mark>scope</mark> is a part of the program in which a name has a particular meaning. Most scopes in C++ are delimited by curly braces.

```cpp
#include <iostream>
// Program for illustration purposes only: It is bad style for a function
// to use a global variable and also define a local variable with the same name int reused = 42; // reused has global scope
int main()
{
int unique = 0; // unique has block scope
// output #1: uses global reused; prints 42 0
std::cout << reused << " " << unique << std::endl;
int reused = 0; // new, local object named reused hides global reused // output #2: uses local reused; prints 0 0
std::cout << reused << " " << unique << std::endl;
// output #3: explicitly requests the global reused; prints 42 0
std::cout << ::reused << " " << unique << std::endl;
return 0; }
```

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

he easiest way to understand the type of r is to <mark>read the definition right to left</mark>. The symbol closest to the name of the variable (in this case the & in &r) is the one that has the most immediate effect on the variable’s type. Thus, we know that r is a reference. The rest of the declarator determines the type to which r refers. The next symbol, * in this case, says that the type r refers to is a pointer type. Finally, the base type of the declaration says that r is a reference to a pointer to an int.

## 2.4 const Qualifier
To make a variable unchangeable by defining the variable's type as const (must be initialized)
#### Initialization and const
The constness of a variable matters only for the operations that might change this variable. *For example*

```cpp
int i=42;
cons int ci=i;
int j=ci;
```
#### By default, const objects are local to a file
* When a const is initialized as a compile-time constant,the compile will replace uses of the vaiable with its corresponding value.
* To share a const varaiable across multiple files but whose initializer is not a constant expression. We want to define the const in one file and declare it in the other files that use that object.

```cpp
// file_1.cc defines and initializes bufSize
extern const int bufSize=fcn();
//file_1.h
extern const int bufSize;
```
### 2.4.1 References to const
Unlike an ordinary reference, a reference to const can not be used to change the object to which the reference is bound.

```cpp
const int ci-1024;
const int &r1=ci;
r1=42;// error, r1 is a reference to const
int &r2=ci;//erroe, non const reference to a const object
```
#### Initialization and References to const
Two exceptions to the rule that the type of a reference must match the type of the object to which it refers.

*Initialize a reference to const from any expression that can be converted to the type of the reference.

```cpp
int i=42;
const int &r1=i;//we can bind a const int& to a plain int object
const int &r2=42;
int &r3=r2;//error,r3 is a plian, non const reference
```
Consider a case where the type can not convert to the a referece to const
```cpp
double dval = 3.14;
const int &ri = dval;
```
To ensure that the object to which ri is bound is an int, the compiler transforms this code into something like

```cpp
const int temp = dval;// create a temporary const int from the double
const int &ri = temp;// bind ri to that temporary
```
<mark>Now consider what could happen if this initialization were allowed but ri was not const. </mark> 

#### A Reference to const May Refer to an Object That Is Not const
```cpp
int i=42;
int &r1=i;// r1 bound to i
cons int &r2=i;//r2 also bound to i; but cannot be used to change i
r1=0;//i=0 now
r2=0;// erroe ,r2 is a ference to const
```
### 2.4.2 Pointers and const
* A pointer to const may not be used to change the object to which the pointer points.
* There is no guarantee that an object pointed to by a pointer too sonst won't change.

```cpp
const double pi = 3.14;   // pi is const; its value may not be changed
double *ptr = &pi;        // error: ptr is a plain pointer
const double *cptr = &pi; // ok: cptr may point to a double that is const
*cptr = 42;
double dval = 3.14;       // dval is a double; its value can be changed
cptr = &dval;
```
#### const Pointers
Since pointers are objects, we can have a pointer that is itself const.

```cpp
int errNumb = 0;
int *const curErr = &errNumb;  // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```
<mark>To understand declarations: read from tight to left.</mark>

* The fact that a pointer is itself const says nothing about whether we can use the pointer to change the underlying object.

```cpp
*pip = 2.72;     // error: pip is a pointer to const
// if the object to which curErr points (i.e., errNumb) is nonzero
if (*curErr) {
    errorHandler();
    *curErr = 0; // ok: reset the value of the object to which curErr is bound
}
```
### 2.4.3 Top-Level const
* Talk about independently whether a pointer (**top-level const**) is const and whether the objects(**low-level const**) to which it can point are const. 
* Generally, top-level const: build-in arithmetic types, a class type, or a pointer type. low-type const appears in the base type of compound types such as pointers or references.

```cpp
int i = 0;
int *const p1 = &i;  // we can't change the value of p1; const is top-level
const int ci = 42;   // we cannot change ci; const is top-level
const int *p2 = &ci; // we can change p2; const is low-level
const int *const p3 = p2; // right-most const is top-level, left-most is not
const int &r = ci;  // const in reference types is always low-level
```
The distinction between top-level and low-level matters when we copy an object.


When we copy an object, top-level consts are ignored:

```cpp
i = ci;  // ok: copying the value of ci; top-level const in ci is ignored
p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored
```
On the other hand, low-level const is never ignored. ???

```cpp
int *p = p3; // error: p3 has a low-level const but p doesn't
p2 = p3;     // ok: p2 has the same low-level const qualification as p3
p2 = &i;     // ok: we can convert int* to const int*
int &r = ci; // error: can't bind an ordinary int& to a const int object
const int &r2 = i; // ok: can bind const int& to plain int
```
###2.4.4 constexpr and Constant Expressions
* A constant expression is an expression whose valuse cannot change and that can be evaluated at compile time.
* A const object that is initialized from a constant expression is also a constant expression.
* depend on type(const) and initilization(fix)

#### constexpr Variable 
Under the new standard, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration. Variables declared as constexpr are implicitly const and must be initialized by constant expressions.

```cpp
constexpr int mf = 20;        // 20 is a constant expression
constexpr int limit = mf + 1; // mf + 1 is a constant expression
constexpr int sz = size();    // ok only if size is a constexpr function
```
#### Literal Types
Because a constant expression is one that can be evaluated at compile time, there are limits on the types that we can use in a constexpr declaration. The types we can use in a constexpr are known as “literal types” because they are simple enough to have literal values.

* Variables defined inside a function ordinarily are not stored at a fixed address. Hence, we cannot use a constexpr pointer to point to such variables. On the other hand, the address of an object defined outside of any function is a constant expression, and so may be used to initialize a constexpr pointer. 

#### Pointers and constexpre
* constexpr applies to pointer.(impose a top-level const)
```cpp
int x;
```

##2.5 Dealing with Types

### 2.5.1. Type Aliases
A <mark>type alias</mark> is a name that is a synonym for another type.

```CPP
typedef double wages; // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
```

The new standard introduced a second way to define a type alias, via an alias.

```CPP
using SI = Sales_item; // SI is a synonym for Sales_item
```

#### Pointers, const, and Type Aliases
```cpp
typedef char *pstring;
const pstring cstr = 0; // cstr is a constant pointer to char
const pstring *ps; // ps is a pointer to a constant pointer to char
const char *cstr = 0; // wrong interpretation of const pstring cstr
```

* const pstring is a constant pointer to char—not a pointer to const char.
* This rewrite declares cstr as a pointer to const char rather than as a const pointer to char.

### 2.5.2. The auto Type Specifier
When we write a program, it can be surprisingly difficult—and sometimes even impossible—to determine the type of an expression. Under the new standard, we can let the compiler figure out the type for us by using the <mark>auto</mark> type specifier.

* auto tells the compiler to deduce the type from the initializer.

```cpp
auto item = val1 + val2; // item initialized to the result of val1 + val2
auto i=0,*p=&i; //ok: i is int and p isapointerto int 
auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
```

#### Compound Types, const, and auto
```cpp
int i = 0, &r = i;
auto a=r; // a isan int (r isanaliasfor i,whichhastype int)
```

* auto ordinarily ignores top-level consts. As usual in initializations, low-level consts, such as when an initializer is a pointer to const, are kept:

```cpp
const int ci = i, &cr = ci;
auto b = ci; // b is an int (top-level const in ci is dropped)
auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
auto d =&i; // d isan int*(& ofan int objectis int*)
auto e = &ci; // e is const int*(& of a const object is low-level const)
const auto f = ci; // deduced type of ci is int; f has type const int
```
We can also specify that we want a reference to the auto-deduced type. 

```cpp
auto&g=ci; // g isa constint& thatisboundto ci
auto &h = 42; // error: we can't bind a plain reference to a literal const auto &j = 42; // ok: we can bind a const reference to a literal
```
＊ As usual, the initializers must provide consistent auto-deduced types.

###2.5.3. The decltype Type Specifier
<mark> decltype </mark>define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the variable.

```cpp
decltype(f()) sum = x; // sum has whatever type f returns
```
When the expression to which we apply decltype is a variable, decltype returns the type of that variable, including top-level const and references

```cpp
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x 
decltype(cj) z; // error: z is a reference and must be initialized
```

#### decltype and References
When we apply decltype to an expression that is not a variable, we get the type that that expression yields.

```cpp
//decltype ofanexpressioncanbeareferencetype
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int 
decltype(*p) c; // error: c is int& and must be initialized

```
If we wrap the variable’s name in one or more sets of parentheses, decltype on such an expression yields a reference

```cpp
//decltype ofaparenthesizedvariableisalwaysareference 
decltype((i)) d; // error: d is int& and must be initialized 
decltype(i) e; // ok: e is an (uninitialized) int

```



##2.6 Defining Our Own Data Structure

* C++ programs use the preprocessor to define **header guards**, to avoid include the header multiple times.
* Variables in the structure could be initilized under the new standard.  
 
 ```cpp
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
 ```

The whole program

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
int main()
{
    Sales_data data1, data2;
    // code to read into data1 and data2
    double price = 0;   // price per book, used to calculate total revenue
    // read the first transactions: ISBN, number of books sold, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	// read the second transaction
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;



	if (data1.bookNo == data2.bookNo) {
   		 unsigned totalCnt = data1.units_sold + data2.units_sold;
	   	 double totalRevenue = data1.revenue + data2.revenue;
   		 // print: ISBN, total sold, total revenue, average price per book
	    std::cout << data1.bookNo << " " << totalCnt
   	           << " " << totalRevenue << " ";
   		 if (totalCnt != 0)
      		  std::cout << totalRevenue/totalCnt << std::endl;
	    else
   		     std::cout << "(no sales)" << std::endl;
	    return 0; // indicate success
	} else {  // transactions weren't for the same ISBN
   		 std::cerr << "Data must refer to the same ISBN"
      	        << std::endl;
	    return -1; // indicate failure
	}
    
}
```
