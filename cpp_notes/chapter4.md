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

