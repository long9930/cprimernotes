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
