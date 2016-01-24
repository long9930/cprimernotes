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

## 2.3

## 2.4

```cpp
int x;
```