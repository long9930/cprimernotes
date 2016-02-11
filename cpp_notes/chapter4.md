## C++ Primer C4.4
The left-hand operand of an assignment operator must be a 

* ```modifiable``` 
* ```lvalue ```

Every C++ expression is either an ```lvalue``` or an ```rvalue```. An ```lvalue refers to an object that persists beyond a single expression```. You can think of an lvalue as an object that has a name. All variables, including nonmodifiable (const) variables, are lvalues. An ```rvalue is a temporary value that does not persist beyond the expression that uses it```. To better understand the difference between lvalues and rvalues.

an rvalue is when the expression result will not survive past the end of said expression. An lvalue will. This basic principle is what enables move semantics and rvalue references- that you can modify them without issue, because you know that object's life is over.

For example, given

```cpp
int i = 0, j = 0, k = 0; // initializations, not assignment
const int ci = i;        // initialization, not assignment
```

Each of these assignments is illegal:


```cpp
1024 = k;      // error: literals are rvalues
i + j = k;     // error: arithmetic expressions are rvalues
ci = k;        // error: ci is a const (nonmodifiable) lvalue
```

* The result of an assignment is its left-hand operand, which is an lvalue. 
* The type of the result is the type of the left-hand operand. 
* If the types of the left and right operands differ, the right-hand operand is converted to the type of the left:

```cpp
k = 0;          //  result: type int, value 0
k = 3.14159;    //  result: type int, value 3
```

Under the new standard, we can use a braced initializer list on the right-hand side:

```cpp
vector<int> vi;             // initially empty
vi = {0,1,2,3,4,5,6,7,8,9}; // vi now has ten elements, values 0 through 9
```

If the left-hand operand is of a built-in type, 
* the initializer list may contain at most one value, 
* that value must not require a narrowing conversion 

```cpp
k = {3.14};                 // error: narrowing conversion
```

For class types, what happens depends on the details of the class. 

* In the case of vector, the ```vector``` template defines its own version of an assignment operator that can take an initializer list. This operator replaces the elements of the left-hand side with the elements in the list on the right-hand side.

* The initializer list may be empty. In this case, the compiler generates a value-initialized (§ 3.3.1, p. 98) temporary and assigns that value to the left-hand operand.


###Assignment Is Right Associative###
Associativity (or fixity) of an operator is a property that determines how operators of the same precedence are grouped in the absence of parentheses. If an operand is both preceded and followed by operators (for example, "^ 4 ^"), and those operators have equal precedence, then the operand may be used as input to two different operations. The choice of which operations to apply the operand to, is determined by the "associativity" of the operators. Operators may be
* ```associative``` (operations can be grouped arbitrarily)
* ```left-associative``` (operations are grouped from the left ```a ~ b ~ c => (a ~ b) ~ c```)
* ```right-associative``` (operations are grouped from the right ```a ~ b ~ c => a ~ (b ~ c)```) 
* ```non-associative``` (operations can not be chained, often because the output type is incompatible with the input types). 

Assignment is right associative:
```cpp
int ival, jval;
ival = jval = 0; // ok: each assigned 0
```
Because assignment is right associative, the right-most assignment, jval = 0, is the right-hand operand of the left-most assignment operator. ```ival = (jval = 0)```

Because assignment returns its left-hand operand, the result of the right-most assignment (i.e., jval) is assigned to ival.
* Each object in a multiple assignment must have the same type as its right-hand neighbor 
* or a type to which that neighbor can be converted:


```cpp
int ival, *pval; // ival is an int; pval is a pointer to int
ival = pval = 0; // error: cannot assign the value of a pointer to an int
string s1, s2;
s1 = s2 = "OK";  // string literal "OK" converted to string
```

The first assignment is illegal because ival and pval have different types and there is no conversion from the type of pval (int*) to the type of ival (int). It is illegal even though zero is a value that can be assigned to either object.
On the other hand, the second assignment is fine. The string literal is converted to string, and that string is assigned to s2. The result of that assignment is s2, which has the same type as s1.

###Assignment Has Low Precedence###
* Assignments often occur in conditions. 
* Because assignment has relatively low precedence, we usually must parenthesize the assignment for the condition to work properly. 

To see why assignment in a condition is useful, consider the following loop. We want to call a function until it returns a desired value—say, 42:

```cpp
// a verbose and therefore more error-prone way to write this loop
int i = get_value();  // get the first value
while (i != 42) {
    // do something ...
    i = get_value();  // get remaining values
}
```

Here we start by calling get_value followed by a loop whose condition uses the value returned from that call. The last statement in this loop makes another call to get_value, and the loop repeats. We can write this code more directly as

```cpp
int i;
// a better way to write our loop---what the condition does is now clearer
while ((i = get_value()) != 42) {
    // do something ...
}
```

The condition now more clearly expresses our intent: We want to continue until get_value returns 42. The condition executes by assigning the result returned by get_value to i and then comparing the result of that assignment with 42.

* Without the parentheses, the operands to != would be the value returned from get_value and 42. The true or false result of that test would be assigned to i—clearly not what we intended!

###Beware of Confusing Equality and Assignment Operators###
The fact that we can use assignment in a condition can have surprising effects:

```cpp
if (i = j)
```

The condition in this if assigns the value of j to i and then tests the result of the assignment. If j is nonzero, the condition will be true. The author of this code almost surely intended to test whether i and j have the same value:

```cpp
if (i == j)
```

Bugs of this sort are notoriously difficult to find. Some, but not all, compilers are kind enough to warn about code such as this example.

###Compound Assignment Operators###

* We often apply an operator to an object and then assign the result to that same object.
```cpp
int sum = 0;
// sum values from 1 through 10 inclusive
for (int val = 1; val <= 10; ++val)
    sum += val; //  equivalent to sum = sum + val
```

This kind of operation is common not just for addition but for the other arithmetic operators and the bitwise operators. There are compound assignments for each of these operators:

```cpp
 +=   -=   *=   /=   %=         // arithmetic operators
<<=  >>=   &=   ^=   |=         // bitwise operators;
```

Each compound operator is essentially equivalent to

```cpp
a = a op b;
```

with the exception that, 
* when we use the compound assignment, the left-hand operand is evaluated only once. 
* If we use an ordinary assignment, that operand is evaluated twice: once in the expression on the right-hand side and again as the operand on the left hand. In many, perhaps most, contexts this difference is immaterial aside from possible performance consequences.



## C++ Primer C4.5 C4.6
###4.5 Increment and Decrement Operators `++` and `--`  
Meaning: adding or subtracting 1 from an object.  
Two forms: prefix and postfix.  

* **prefix**: `++i` increment its operand and yield the changed object as result  
* **postfix**: `i++` yield a copy of the original unchanged value as result and then change the operand  

Example 1:  

~~~cpp
int i = 0, j;
j = ++i; // j=1, i=1
j = i++; // j=1, i=2
~~~

Use Postfix Operators only when necessary!!!

####Combining Dereference and Increment in a Single Expression  

Example 2:

~~~cpp
//print elements of a vector up to the first negative value

auto pbeg = v.begin();
while (pbeg != v.end() && *beg>= 0)
	cout << * pbeg++ << endl;
~~~

`*pbeg++` here is equivalent to `*(pbeg++)`  

We can also write it like as the following:

~~~cpp
auto pbeg = v.begin();
while (pbeg != v.end() && *beg>= 0)
	cout << * pbeg << endl;
	++pbeg
~~~

####Operands Can Be Evaluated in Any Order
Most operators give no guarantee as to the order in which operands will be evaluated. This matters when on subexoression changes the value of an operand that is used in another subexpression.

Example 3:

~~~cpp
//Capitalize the first word in the input

while (beg != s.end() && !isspace(*beg))
	*beg = toupper(*beg++) //error: this assighnment is undefined
~~~

The compiler might evaluate this expression as either

~~~cpp
*beg = toupper(*beg);  //if left-hand side is evaluated first
*(beg+1) = toupper(*beg); //if right-hand side is evaluated first
~~~


###4.6 The Member Acess Operators `.` and `->`

* **dot**: fetch a member from an onject of class type
* **arrow**: used for a pointer  `ptr->mem` is equivalent to `(*ptr).mem`

Example 4:

~~~cpp
string s1 = "a string", *p = &s1;
auto n = s1.size();
n = (*p).size();
n = p->size();
~~~





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


## References
[Understanding lvalues and rvalues in C and C++](http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c)