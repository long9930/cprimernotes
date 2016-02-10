## C++ Primer C4.4



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
