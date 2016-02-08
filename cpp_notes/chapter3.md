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
      



  
