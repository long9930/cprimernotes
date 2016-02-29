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


## 3.2. Primitive Build-in Types
Our examples assume the following code:

```cpp
#include <string> 
using std::string;
```

###3.2.1. Defining and Initializing strings
The most common ways to initialize strings.

```cpp
string s1;
string s2(s1);
string s2=s1;
string s3("value");
string s3="value";
string s4(n,'c');
```

When we initialize a variable using =, we are asking the compiler to <mark>copy initialize</mark> the object by copying the initializer on the right-hand side into the object being created. Otherwise, when we omit the =, we use <mark>direct initialization.<mark>

* When we initialize a variable from more than one value, such as in the initialization of s4 above, we must use the direct form of initialization:

```cpp
string s5 = "hiya"; // copy initialization
string s6("hiya"); // direct initialization
string s7(10, 'c'); // direct initialization; s7 is cccccccccc
```
When we want to use several values, we can indirectly use the copy form of initialization by explicitly creating a (temporary) object to copy

```cpp
string s8 = string(10, 'c'); // copy initialization; s8 is cccccccccc
string temp(10, 'c'); // temp is cccccccccc string s8 = temp; // copy temp into s8
```
###3.2.2. Operations on strings
String options:

```cpp
os<<s		Write s onto stream os. Return os.
is>>s		Reads whitespace-sparated string from is into s. Return is
getline(is,s)		reads a line of input from is into s. Return is.
s.empty()		Returns true if s is empty; otherwise false.
s.size()		Return size
s[n]		Return a reference to the char at position n in s; positions start at 0.
s1+s2		Return concatenation
<,<=,>,>=		Comparisons are case-sensitive and use dictionary ordering
```
####Reading and Writing strings

Sometimes we do not want to ignore the whitespace in our input. In such cases, we can use the getline function instead of the >> operator. 

```cpp
int main()
{
string line;
// read input a line at a time until end-of-file
while (getline(cin, line)) cout << line << endl;
return 0; }
```
The string empty and size Operations

```cpp
while (getline(cin, line))
if (!line.empty())
cout << line << endl;
string line;
// read input a line at a time and print lines that are longer than 80 characters 
while (getline(cin, line))
if (line.size() > 80) cout << line << endl;
```
* it can be tedious to type string::size_type. Under the new standard, we can ask the compiler to provide the appropriate type by using auto or decltype

####Comparing strings
The comparisons are case- sensitive—upper- and lowercase versions of a letter are different characters.

1. If two strings have different lengths and if every character in the shorter string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one.

2. If any characters at corresponding positions in the two strings differ, then the result of the string comparison is the result of comparing the first character at which the strings differ.

```cpp
string str = "Hello";
string phrase = "Hello World"; 
string slang = "Hiya";
```
Using rule 1, we see that str is less than phrase. By applying rule 2, we see that slang is greater than both str and phrase.

####Adding two strings
```cpp
string s1 = "hello, ", s2 = "world\n"; 
string s3 = s1 + s2; // s3 is hello, world\n 
s1+=s2; // equivalent to s1=s1+s2
```
```cpp
string s4 = s1 + ", "; // ok: adding a string and a literal 
string s5 = "hello" + ", "; // error: no string operand 
string s6 = s1 + ", " + "world"; // ok: each + has a string operand 
string s7 = "hello" + ", " + s2; // error: can't add string literals
```
###3.2.3. Dealing with the Characters in a string
These functions are defined in the cctype header.

Refer to the book.

####Processing Every Character? Use Range-Based for

<mark>range for</mark> statement statement iterates through the elements in a given sequence and performs some operation on each value in that sequence. 

```cpp
string str("some string");
// print the characters in str one character to a line
for (auto c : str) // for every char in str
cout << c << endl; // print the current character followed by a newline
```
```cpp
string s("Hello World!!!");
// punct_cnt has the same type that s.size decltype(s.size()) punct_cnt = 0; // count the number of punctuation characters in s
for(autoc:s) if (ispunct(c))
++punct_cnt; 
// forevery char in s
// if the character is punctuation
// increment the punctuation counter
cout << punct_cnt<< " punctuation characters in " << s << endl;
```
* 3 punctuation characters in Hello World!!!

####Using a Range for to Change the Characters in a string

```cpp
string s("Hello World!!!");
// convert s to uppercase
for (auto &c : s) // for every char in s (note: c is a reference)
c = toupper(c); // c is a reference, so the assignment changes the char in s
cout << s << endl;
```
####Processing Only Some Characters?

```cpp
string s("some string"); if (!s.empty())
s[0] = toupper(s[0]);
```

####Using a Subscript for Iteration
```cpp
for (decltype(s.size()) index = 0;
index != s.size() && !isspace(s[index]); ++index) s[index] = toupper(s[index]); // capitalize the current
character
```
* SOME string
####Using a Subscript for Random Access

```cpp
const string hexdigits = "0123456789ABCDEF"; // possible hex digits 
cout << "Enter a series of numbers between 0 and 15"
<< " separated by spaces. Hit ENTER when finished: "
<< endl;
string result; // will hold the resulting hexify'd string 
string::size_type n; // hold numbers from the input
while (cin >> n)
if (n < hexdigits.size()) // ignore invalid input result += hexdigits[n]; // fetch the indicated hex digit
cout << "Your hex number is: " << result << endl;
```

12 0 5 15 8 15

Your hex number is: C05F8F


## 3.3 Library vector Type
## 3.3 Library *vector* Type
* Vector: collection of same type objects.(index)(container)
* To use a vector, must include header.

```cpp
#include <vector>
using std::vector
```
* A *vector* is a class template.
   *   C++ has both class and function templates
   *   Templates are not themselves functions or classes(instructions)
   *   instantiation
   *    we specify which class to instantiate by supplying additional information.(angle brackets following the template's name)
   *    hold type(nonreference) 
  
```cpp
vector<int> ivec;// ivec holds objects of type int
vector<Sales_item> Sales_vec; // holds Sales_items
vector<vector<string>> file;  // vector whose elements are vectors
vector<vector<string> > file;
```
### 3.3.1 Defining and Intializing *vector*s

![](initialize.jp2)

* empty vector

```cpp
vector<string> svec; // default initialization; svec has no elements
```
   * the use of empty vector: add elements to empty vector ar run time.

* copy elements from another vector: the two vectors must be the same type

```cpp
vector<int> ivec;             // initially empty
// give ivec some values
vector<int> ivec2(ivec);      // copy elements of ivec into ivec2
vector<string> svec(ivec2);   // error: svec holds strings, not ints
```
#### List initializeing a *vector*

* curly braces

```cpp
vector<string> v1{"a", "an", "the"};  // list initialization
vector<string> v2("a", "an", "the");  // error
```

#### Creating a Specified Number of Elements

```cpp
vector<int> ivec(10, -1);       // ten int elements, each initialized to -1
vector<string> svec(10, "hi!"); // ten strings; each element is "hi!"
```

* omit value and supply only size
      * libarary creates a value-initialized element initializer for use.
      * if our vector holds objects of a type that we cannot default initialize, then we must supply an initial element value
      * if we supply an element count without also supplying an initial value, we must use the **direct form** of initialization.

```cpp
vector<int> ivec(10);    // ten elements, each initialized to 0
vector<string> svec(10); // ten elements, each an empty string
```

```cpp
vector<int> vi = 10;    // error: must use direct initialization to supply a size
```

###3.3.2 Adding Elements to a *vector*

* *push_back*: The push_back operation takes a value and “pushes” that value as a new last element onto the “back” of the vector

```cpp
vector<int> v2;        // empty vector
for (int i = 0; i != 100; ++i)
    v2.push_back(i);    // append sequential integers to v2
// at end of loop v2 has 100 elements, values 0 . . . 99
```

```cpp
// read words from the standard input and store them as elements in a vector
string word;
vector<string> text;       // empty vector
while (cin >> word) {
    text.push_back(word);  // append word to text
}
```

* vectors grow efficiently

### 3.3.3 Other *vector* Operations

![](operations.jp2)

* access the elements of a vector(same with access the characters in a string) 

```cpp
vector<int> v{1,2,3,4,5,6,7,8,9};
for (auto &i : v)     // for each element in v (note: i is a reference,control variable)
    i *= i;           // square the element value
for (auto i : v)      // for each element in v
    cout << i << " "; // print the element
cout << endl;
```
* *size* return returns a value of the *size_type* defined by the corresponding vector type.(string)
* equality
* relational operators:(dictionary order)
   * If the vectors have differing sizes, but the elements that are in common are equal, then the vector with fewer elements is less than the one with more elements.
   * If the elements have differing values, then the relationship between the vectors is determined by the relationship between the first elements that differ.
   

#### computing a *vector* Index
* subscript operator
* ***EX***:
clustering:
42 65 95 100 39 67 95 76 88 76 83 92 76 93

```cpp
// count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
unsigned grade;
while (cin >> grade) {      // read the grades
    if (grade <= 100)       // handle only valid grades
        ++scores[grade/10]; // increment the counter for the current cluster
}
```
* subscript does not add elements
wrong!

```cpp
vector<int> ivec;   // empty vector
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec[ix] = ix;  // disaster: ivec has no elements
```
right!

```cpp
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec.push_back(ix);  // ok: adds a new element with value ix
```

**Subscript only elements that are known to exist!**

```cpp
vector<int> ivec;      // empty vector
cout << ivec[0];       // error: ivec has no elements!
```

```cpp
vector<int> ivec2(10); // vector with ten elements
cout << ivec2[10];     // error: ivec2 has elements 0 . . . 9
```
### 3.5.1 Defining and Initializing Build-in Arrays
**Arrays**: 

* Compound type; 
* Form: a[d] a is the name and d is the dimension. d must be **constant  expression**.
* Specify a type for array when define an array, cannot use *auto*.
* Array holds objects, thus no arrays of references.

#### Explicity Initializing Array Elements
* we can omit the dimension. 

```cpp
int a2[] = {0, 1, 2}// an array of dimension 3
```

* If we specify a dimension, the number of initializers must not exceed the specified size.

```cpp
string a4[3] = {"hi", "bye"}; // same as a4[] =  {"hi", "bye", ""}
int a5[2] = {0,1,2};          // error: too many initializers
```
#### Character Arrays Are Special
 * We can initialize such arrays from a string literal.
 * string literals end with a null character.

 ```cpp
 char a3[] = "C++";                 // null terminator added automatically
const char a4[6] = "Daniel";       // error: no space for the null!
```
#### No copy or Assignment.
#### Understanding Complicated Array Declarations
```cpp
int *ptrs[10];            //  ptrs is an array of ten pointers to int
int &refs[10] = /* ? */;  //  error: no arrays of references
int (*Parray)[10] = &arr; //  Parray points to an array of ten ints
int (&arrRef)[10] = arr;  //  arrRef refers to an array of ten ints
int *(&arry)[10] = ptrs; // arry is a reference to an array of ten pointers
```
### 3.5.2 Accessing the Elements of an Array
* we can use a range for or the subscript operator to access elements of an array.
* the indices start at 0.
* When we use a variable to subscript an array, we normally should define that variable to have type size$\_$t.The size$\_$t type is defined in the *cstddef* header.

```cpp
// count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
unsigned grade;
while (cin >> grade) {
    if (grade <= 100)
        ++scores[grade/10]; // increment the counter for the current cluster
}
```

**for**

```cpp
for (auto i : scores)      // for each counter in scores
    cout << i << " ";      // print the value of that counter
cout << endl;
```

### 3.5.3 Pointers and Array
* When we use an array, the compiler automatically substitutes a pointer to the first element. 
* The operations on arrays are often operations on pointers.

```cpp
string nums[] = {"one", "two", "three"};  // array of strings
string *p = &nums[0];   // p points to the first element in nums

string *p2 = nums;      // equivalent to p2 = &nums[0]
```
```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
auto ia2(ia); // ia2 is an int* that points to the first element in ia
```
#### Pointers are Iterators & The library begin and end function 
* Pointers to array elements support the same operations as iterators on vectors or strings. (increment)

```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr; // p points to the first element in arr
++p;          // p points to arr[1]

int *e = &arr[10]; // pointer just past the last element in arr

for (int *b = arr; b != e; ++b)
    cout << *b << endl; // print the elements in arr
    
    // pbeg points to the first and pend points just past the last element in arr
int *pbeg = begin(arr),  *pend = end(arr);
// find the first negative element, stopping if we've seen all the elements
while (pbeg != pend && *pbeg >= 0)
    ++pbeg;
```

#### Pointer Arithmetic
* When we add (or subtract) an integral value to (or from) a pointer, the result is a new pointer.

```cpp
constexpr size_t sz = 5;
int arr[sz] = {1,2,3,4,5};
int *ip = arr;     // equivalent to int *ip = &arr[0]
int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr
```
* Subtracting two pointers gives us the distance between those pointers.

```cpp
auto n = end(arr) - begin(arr); // n is 5, the number of elements in arr
```
* Relational operators: 

```cpp
int *b = arr, *e = arr + sz;
while (b < e) {
    // use *b
    ++b;
}

int i = 0, sz = 42;
int *p = &i, *e = &sz;
// undefined: p and e are unrelated; comparison is meaningless!
while (p < e)
```

#### Interaction between dereference and pointer arithmetic
``` cpp
int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
int last = *(ia + 4); // ok: initializes last to 8, the value of ia[4]

last = *ia + 4;  // ok: last = 4, equivalent to ia[0] + 4
```

#### Subscript and Pointers

```cpp
int ia[] = {0,2,4,6,8};  // array with 5 elements of type int

int i = ia[2];  // ia is converted to a pointer to the first element in ia
// ia[2] fetches the element to which (ia + 2) points

int *p = ia;    // p points to the first element in ia
i = *(p + 2);   // equivalent to i = ia[2]
```

### 3.5.4 C-Style Character Strings
在c++中，以数组的方式定义字符串，该字符串储存在数组中，并以null结束。
原本可用于字符串的function现在不可用， 要是用c －library 的函数来进行相同的运算。

* store in character array
* end with null

```cpp
char ca[] = {'C', '+', '+'};  // not null terminated
cout << strlen(ca) << endl;   // disaster: ca isn't null terminated
```
**function**
![](1.jpg)
**Comparison & Concatenating & Coping**

* Remember that when we use an array, we are really using a pointer to the first element in the array

```cpp
const char ca1[] = "A string example";
const char ca2[] = "A different string";
if (ca1 < ca2)  // undefined: compares two unrelated addresses
```
* To compare two strings

```cpp
if (strcmp(ca1, ca2) < 0) // same effect as string comparison s1 < s2
```
* To concatenate or copy

```cpp
strcpy(largeStr, ca1);     // copies ca1 into largeStr
strcat(largeStr, " ");     // adds a space at the end of largeStr
strcat(largeStr, ca2);     // concatenates ca2 onto largeStr
```

**It's more efficient to use library strings rather that C-style strings**

### 3.5.5 Interfacing to Older Code
**Mixing Library strings and C-style Strings**

* We can use a null-terminated character array to initialize or assign a string.
* We can use a null-terminated character array as one operand (but not both operands) to the string addition operator or as the right-hand operand in the string compound assignment (+=) operator.

```cpp
char *str = s; // error: can't initialize a char* from a string
const char *str = s.c_str(); // ok
```
**Using an Array to Initialize a vector**

```cpp
int int_arr[] = {0, 1, 2, 3, 4, 5};
// ivec has six elements; each is a copy of the corresponding element in int_arr
vector<int> ivec(begin(int_arr), end(int_arr));

// copies three elements: int_arr[1], int_arr[2], int_arr[3]
vector<int> subVec(int_arr + 1, int_arr + 4);
```

**Modern C++ programs should use vectors and iterators instead of built-in arrays and pointers, and use strings rather than C-style array-based character strings.**      


## 3.6 Multidimensional Arrays
Strictly speaking, there are no multidimensional arrays in C++. What are commonly
referred to as multidimensional arrays are actually arrays of arrays.


```cpp
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
// array of size 10; each element is a 20-element array whose elements are arrays of 30
ints
int arr[10][20][30] = {0}; // initialize all elements to 0
```
###Initializing the Elements of a Multidimensional Array
```cpp
int ia[3][4] = { // three elements; each element is an array of size 4
{0, 1, 2, 3}, // initializers for the row indexed by 0
{4, 5, 6, 7}, // initializers for the row indexed by 1
{8, 9, 10, 11} // initializers for the row indexed by 2
};

// equivalent initialization without the optional nested braces for each row
int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

// explicitly initialize only element 0 in each row
int ia[3][4] = {{ 0 }, { 4 }, { 8 }};
// explicitly initialize row 0; the remaining elements are value initialized
int ix[3][4] = {0, 3, 6, 9};
```
###Subscripting a Multidimensional Array

```cpp
// assigns the first element of arr to the last element in the last row of ia
ia[2][3] = arr[0][0][0];
int (&row)[4] = ia[1]; // binds row to the second four-element array in ia
```
In the second example, we define row as a reference to an array of four ints. We
bind that reference to the second row in ia.

```cpp
constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt]; // 12 uninitialized elements
// for each row
for (size_t i = 0; i != rowCnt; ++i) {
// for each column within the row
for (size_t j = 0; j != colCnt; ++j) {
// assign the element's positional index as its value
ia[i][j] = i * colCnt + j;
	}
}
```

###Using a Range for with Multidimensional Arrays

```cpp
size_t cnt = 0;
for (auto &row : ia) // for every element in the outer array
for (auto &col : row) { // for every element in the inner array
col = cnt; // give this element the next value
++cnt; // increment cnt
}
```
```cpp
for (const auto &row : ia) //Why const, for every element in the outer array
for (auto col : row) // for every element in the inner array
cout << col << endl;
```
###Pointers and Multidimensional Arrays
```cpp
//The parentheses in this declaration are essential:
int *ip[4]; // array of pointers to int
int (*ip)[4]; // pointer to an array of four ints
```

```cpp
// p points to an array of four ints
for (auto p = ia; p != ia + 3; ++p) {
// q points to the first element of an array of four ints; that is, q points to an
int
for (auto q = *p; q != *p + 4; ++q)
cout << *q << ' ';
cout << endl;
}
```	
The outer for loop starts by initializing p to point to the first array in ia. That loop
continues until we’ve processed all three rows in ia. The increment, ++p, has the
effect of moving p to point to the next row (i.e., the next element) in ia.

The inner for loop prints the values of the inner arrays. It starts by making q point
to the first element in the array to which p points. The result of *p is an array of four
ints. As usual, when we use an array, it is converted automatically to a pointer to its
first element. The inner for loop runs until we’ve processed every element in the
inner array. 

```cpp
\\More easily
// p points to the first array in ia
for (auto p = begin(ia); p != end(ia); ++p) {
// q points to the first element in an inner array
for (auto q = begin(*p); q != end(*p); ++q)
cout << *q << ' '; // prints the int value to which q
points
cout << endl;
}
```











  
