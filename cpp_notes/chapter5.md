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

* init-statement is used to initialize or assign a starting value that is modified over the course of the loop. 
* condition serves as the loop control. As long as condition evaluates as true, statement is executed. If the first evaluation of condition yields false, statement is not executed. 
* expression usually modifies the variable(s) initialized in init-statement and tested in condition. expression is evaluated after each iteration of the loop. As usual, statement can be either a single or a compound statement.


```cpp
// process characters in s until we run out of characters or we hit a whitespace
for (decltype(s.size()) index = 0;
     index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]); // capitalize the current character
```
the order of evaluation is as follows:
* 1. init-statement is executed once at the start of the loop. In this example, index is defined and initialized to zero.
* 2. Next, condition is evaluated. If index is not equal to s.size() and the character at s[index] is not whitespace, the for body is executed. Otherwise, the loop terminates. If the condition is false on the first iteration, then the for body is not executed at all.
* 3. If the condition is true, the for body executes. In this case, the for body makes the character at s[index] uppercase.
* 4. Finally, expression is evaluated. In this example, index is incremented by 1.

These four steps represent the first iteration of the for loop. Step 1 is executed only once on entry to the loop. Steps 2, 3, and 4 are repeated until the condition evaluates as false—that is, when we encounter a whitespace character in s, or index is greater than s.size().

* It is worth remembering that the visibility of any object defined within the for header is limited to the body of the for loop. Thus, in this example, index is inaccessible after the for completes.

Multiple Definitions in the for Header
* init-statement can define several objects. 
* init-statement may be only a single declaration statement. 
* Thus, all the variables must have the same base type. 
```cpp
// remember the size of v and stop when we get to the original last element
for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
    v.push_back(v[i]);
```

Omitting Parts of the for Header
* We can use a null statement for init-statement when an initialization is unnecessary. 
```cpp
auto beg = v.begin();
for ( /* null */; beg != v.end() && *beg >= 0; ++beg)
    ; // no work to do
```

## C++ Primer C5.5


## C++ Primer C5.6
