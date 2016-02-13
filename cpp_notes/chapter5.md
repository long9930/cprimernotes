## C++ Primer C5.4

###Iterative Statements###
Iterative statements, commonly called loops, provide for repeated execution until a condition is true. 
* while and for statements test the condition before executing the body. 
* do while executes the body and then tests its condition.


###The while Statement###
A while statement repeatedly executes a target statement as long as a condition is true. Its syntactic form is
```cpp
while (condition)
      statement
```

* condition may not be empty. 
* If the first evaluation of condition yields false, statement is not executed.
* The condition can be an expression or an initialized variable declaration. 
* Variables defined in a while condition or while body are created and destroyed on each iteration.
* the condition itself or the loop body must change the value of the expression. Otherwise, the loop might never terminate.


* A while loop is generally used when we want to iterate indefinitely, such as when we read input. 
* A while is also useful when we want access to the value of the loop control variable after the loop finishes.

```cpp
vector<int> v;
int i;
// read until end-of-file or other input failure
while (cin >> i)
    v.push_back(i);
// find the first negative element
auto beg = v.begin();
while (beg != v.end() && *beg >= 0)
    ++beg;
if (beg == v.end())
    // we know that all elements in v are greater than or equal to zero
```
* The first loop reads data from the standard input. We have no idea how many times this loop will execute. The condition fails when cin reads invalid data, encounters some other input failure, or hits end-of-file. 
* The second loop continues until we find a negative value. When the loop terminates, beg is either equal to v.end(), or it denotes an element in v whose value is less than zero. 
* We can use the state of beg outside the while to determine further processing.

###Traditional for Statement###
The syntactic form of the for statement is:
```cpp
for (init-statement condition; expression)
    statement
```
* The for and the part inside the parentheses is often referred to as the for header.
* init-statement must be a declaration statement, an expression statement, or a null statement. Each of these statements ends with a semicolon

```cpp
for (initializer; condition; expression)
      statement
```

## C++ Primer C5.5


## C++ Primer C5.6
